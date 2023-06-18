#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int d, to_reach, n, m;
vector<vector<int>> grid, waypoints;
vector<vector<bool>> visited;


void floodfill(int y, int x) {
    if(visited[y][x]) return;
    visited[y][x] = true;
    if(waypoints[y][x]) to_reach--;
    if(y>0 and abs(grid[y][x]-grid[y-1][x])<=d) floodfill(y-1, x);
    if(x>0 and abs(grid[y][x]-grid[y][x-1])<=d) floodfill(y, x-1);
    if(y<n-1 and abs(grid[y][x]-grid[y+1][x])<=d) floodfill(y+1, x);
    if(x<m-1 and abs(grid[y][x]-grid[y][x+1])<=d) floodfill(y, x+1);
}

int main() {
    ifstream fin("ccski.in");
    ofstream fout("ccski.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fin >> n >> m;
    grid.resize(n, vector<int>(m));
    waypoints.resize(n, vector<int>(m));
    for(auto &x: grid) {
        for(auto &y: x) fin >> y;
    }
    pair<int, int> start;
    int waypoint_cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            fin >> waypoints[i][j];
            if(waypoints[i][j] == 1) {
                waypoint_cnt++;
                start = {i, j};
            }
        }
    }
    int l = 0, r = 1e9;
    int sol;
    while(l<=r) {
        d = (l+r)/2;
        to_reach = waypoint_cnt;
        visited.resize(n, vector<bool>(m));
        floodfill(start.first, start.second);
        if(!to_reach) {
            sol = d;
            r = d-1;
        }
        else l = d+1;
        visited.clear();
    }
    fout << sol << endl;
}