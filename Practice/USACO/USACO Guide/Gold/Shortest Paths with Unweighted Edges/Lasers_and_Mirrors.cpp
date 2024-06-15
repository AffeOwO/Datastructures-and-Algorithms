#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> points(n + 2);
	// lines[0] are vertical, lines[1] are horizontal
	unordered_map<int, vector<int>> lines[2];
	for (int i = 0; i < n + 2; i++) {
		cin >> points[i].first >> points[i].second;
		lines[0][points[i].first].push_back(i);
		lines[1][points[i].second].push_back(i);
	}
	// index of fence post and bool for direction of incoming beam
	// true for horizontal, false for vertical
	queue<pair<int, bool>> q;
	q.push({0, true});
	q.push({0, false});
	// dist[i] is number of edges to reach point i from the laser
	vector<int> dist(n + 2, 1e9);
	dist[0] = 0;
	// BFS to find minimum number of fence posts to direct laser to barn
	while (!q.empty()) {
		int curr = q.front().first;
		bool beamdir = q.front().second;
		q.pop();
		int dir = (beamdir ? 0 : 1);
		int coord = (beamdir ? points[curr].first : points[curr].second);
		for (int point : lines[dir][coord]) {
			if (dist[point] == 1e9) {
				q.push({point, !beamdir});
				dist[point] = dist[curr] + 1;
			}
		}
	}
	cout << (dist[1] == 1e9 ? -1 : dist[1] - 1) << endl;
	return 0;
}