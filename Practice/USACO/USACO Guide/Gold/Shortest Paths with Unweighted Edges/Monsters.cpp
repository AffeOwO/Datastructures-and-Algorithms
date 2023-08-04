#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define mn 1005
using namespace std;

int N, M;
queue<pii> q;
int paths[mn][mn];
pii from[mn][mn];
int oo = INT_MAX;
pii A;
string ans;
bool possible = false;

void retrace(pii node) {  // retrace from final node, adding direction from
	                      // previous node to a string. This string will be
	                      // backwards but will be reversed before output.
	pii origin = from[node.first][node.second];
	if (origin == pii(0, 0)) return;
	if (origin.first == node.first + 1) ans.push_back('U');
	if (origin.first == node.first - 1) ans.push_back('D');
	if (origin.second == node.second + 1) ans.push_back('L');
	if (origin.second == node.second - 1) ans.push_back('R');
	retrace(origin);
}
void check(
    pii origin,
    pii dest) {  // check if the considered destination may be traveled to
	int pl = paths[origin.first][origin.second];
	if (pl + 1 < paths[dest.first][dest.second]) {
		paths[dest.first][dest.second] = pl + 1;
		q.push(dest);
		from[dest.first][dest.second] = origin;
	}
}
bool mora = false;  // false if bfs for monsters, true if bfs for A
void bfs() {
	while (!q.empty()) {
		pii loc = q.front(), next;
		q.pop();
		next = loc;
		next.first++;
		check(loc, next);  // go through adjacent locations
		next = loc;
		next.first--;
		check(loc, next);
		next = loc;
		next.second++;
		check(loc, next);
		next = loc;
		next.second--;
		check(loc, next);
		if (mora && (loc.first == 1 || loc.second == 1 || loc.first == N ||
		             loc.second == M)) {
			cout << "YES" << endl;
			cout << paths[loc.first][loc.second] << endl;
			retrace(loc);
			possible = true;
			return;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			paths[i][j] = oo;
			if (s[j - 1] == '#') paths[i][j] = 0;
			if (s[j - 1] == 'M') {
				q.push(pii(i, j));
				paths[i][j] = 0;
			}
			if (s[j - 1] == 'A') {
				A.first = i;
				A.second = j;
			}
		}
	}
	bfs();        // monster bfs
	mora = true;  // change next bfs to A bfs
	from[A.first][A.second] =
	    pii(0, 0);  // give the retrace a terminating location
	paths[A.first][A.second] = 0;
	q.push(A);  // get ready for next bfs
	bfs();      // bfs with A
	if (possible) {
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	} else cout << "NO" << endl;
}
/*
ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    pair<int, int> A;
    vector<pair<int, int>> M;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<m; j++) {
            matrix[i][j] = s[j];
            if(s[j] == 'A') A = make_pair(i, j);
            else if(s[j] == 'M') M.push_back(make_pair(i, j));
        }
    }
    // for each cell, calculate the min time for a monster to reach it
    vector<vector<int>> mdist(n, vector<int>(m, INT_MAX)); // min dist of each cell to a monster
    for(auto &x: M) {
        vector<vector<int>> dist(n, vector<int>(m, -1)); dist[x.first][x.second] = 0; 
        queue<pair<int, int>> q; q.push(x);
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            int temp = dist[cur.first][cur.second];
            if(mdist[cur.first][cur.second]<=temp) continue;
            mdist[cur.first][cur.second] = dist[cur.first][cur.second];
            if(cur.first>0 and matrix[cur.first-1][cur.second] != '#' and dist[cur.first-1][cur.second] == -1) {
                dist[cur.first-1][cur.second] = temp+1;
                q.push(make_pair(cur.first-1, cur.second));
            }
            if(cur.first<n-1 and matrix[cur.first+1][cur.second] != '#' and dist[cur.first+1][cur.second] == -1) {
                dist[cur.first+1][cur.second] = temp+1;
                q.push(make_pair(cur.first+1, cur.second));
            }
            if(cur.second>0 and matrix[cur.first][cur.second-1] != '#' and dist[cur.first][cur.second-1] == -1) {
                dist[cur.first][cur.second-1] = temp+1;
                q.push(make_pair(cur.first, cur.second-1));
            }
            if(cur.second<m-1 and matrix[cur.first][cur.second+1] != '#' and dist[cur.first][cur.second+1] == -1) {
                dist[cur.first][cur.second+1] = temp+1;
                q.push(make_pair(cur.first, cur.second+1));
            }
        }
    }

    vector<vector<int>> adist(n, vector<int>(m, -1)); adist[A.first][A.second] = 0;
    vector<vector<char>> path(n, vector<char>(m)); path[A.first][A.second] = 'X';
    queue<pair<int, int>> q; q.push(A);
    pair<int, int> bound; bound.first = -1;
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if(cur.first == 0 or cur.second == 0 or cur.first == n-1 or cur.second == m-1) {
            bound = cur;
            break;
        }
        int temp = adist[cur.first][cur.second]+1;
        if(cur.first>0 and adist[cur.first-1][cur.second] == -1 and matrix[cur.first-1][cur.second] != '#' and mdist[cur.first-1][cur.second]>temp) {
            adist[cur.first-1][cur.second] = temp;
            q.push(make_pair(cur.first-1, cur.second));
            path[cur.first-1][cur.second] = 'U';
        }
        if(cur.first<n-1 and adist[cur.first+1][cur.second] == -1 and matrix[cur.first+1][cur.second] != '#' and mdist[cur.first+1][cur.second]>temp) {
            adist[cur.first+1][cur.second] = temp;
            q.push(make_pair(cur.first+1, cur.second));
            path[cur.first+1][cur.second] = 'D';
        }
        if(cur.second>0 and adist[cur.first][cur.second-1] == -1 and matrix[cur.first][cur.second-1] != '#' and mdist[cur.first][cur.second-1]>temp) {
            adist[cur.first][cur.second-1] = temp;
            q.push(make_pair(cur.first, cur.second-1));
            path[cur.first][cur.second-1] = 'L';
        }
        if(cur.second<m-1 and adist[cur.first][cur.second+1] == -1 and matrix[cur.first][cur.second+1] != '#' and mdist[cur.first][cur.second+1]>temp) {
            adist[cur.first][cur.second+1] = temp;
            q.push(make_pair(cur.first, cur.second+1));
            path[cur.first][cur.second+1] = 'R';
        }
    }

    if(bound.first == -1) cout << "NO" << endl;
    else {
        //cout << bound.first << " " << bound.second << endl;
        cout << "YES" << endl;
        vector<char> sol;

        pair<int, int> cur = bound;
        while(path[cur.first][cur.second] != 'X') {
            char temp = path[cur.first][cur.second];
            sol.push_back(temp);
            switch(temp) {
                case 'D':
                    cur.first--;
                    break;
                case 'U':
                    cur.first++;
                    break;
                case 'R':
                    cur.second--;
                    break;
                case 'L':
                    cur.second++;
                    break;
            }
            
        }
        cout << sol.size() << endl;
        for(int i=sol.size()-1; i>=0; i--) cout << sol[i];
        cout << endl;
    }
*/