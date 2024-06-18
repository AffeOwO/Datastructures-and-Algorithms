#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

int main() {
	// see /general/fast-io
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int test_num;
	std::cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int row_num;
		int col_num;
		std::cin >> row_num >> col_num;
		vector<vector<int>> grid(row_num, vector<int>(col_num));
		for (int r = 0; r < row_num; r++) {
			for (int c = 0; c < col_num; c++) { std::cin >> grid[r][c]; }
		}

		vector<vector<int>> longest_consec(row_num, vector<int>(col_num));
		for (int r = 0; r < row_num; r++) {
			int curr = -1;
			int streak = 0;
			for (int c = 0; c < col_num; c++) {
				if (grid[r][c] == curr) {
					streak++;
				} else {
					curr = grid[r][c];
					streak = 1;
				}
				longest_consec[r][c] = streak;
			}
		}

		long long total = 0;
		for (int c = 0; c < col_num; c++) {
			vector<pair<int, int>> rel_streaks;
			int curr_sum = 0;  // the current amt of valid submatrices
			int curr = grid[row_num - 1][c];
			// for each row in reverse, count # of valid submatrices that start
			// at that cell
			for (int r = row_num - 1; r >= 0; r--) {
				// if we encounter a diff number, just up & reset everything
				if (grid[r][c] != curr) {
					curr = grid[r][c];
					curr_sum = 0;
					rel_streaks = vector<pair<int, int>>();
				}

				/*
				 * the total # of elements that were killed
				 * between this element & the last one
				 */
				int popped = 0;
				// while this current row can possibly be a chokehold
				while (!rel_streaks.empty() &&
				       longest_consec[r][c] < rel_streaks.back().first) {
					// subtract the # of rectangles this chokehold made invalid
					curr_sum -=
					    (rel_streaks.back().second + 1) *
					    (rel_streaks.back().first - longest_consec[r][c]);
					// add the number of kills this one got & kill this one
					// itself
					popped += rel_streaks.back().second + 1;
					rel_streaks.pop_back();
				}
				rel_streaks.push_back({longest_consec[r][c], popped});
				// add the submatrices of height 1
				curr_sum += longest_consec[r][c];
				total += curr_sum;
			}
		}
		cout << total << '\n';
	}
}