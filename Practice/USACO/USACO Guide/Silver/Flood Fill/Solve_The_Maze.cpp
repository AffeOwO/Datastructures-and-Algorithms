#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, m;
vector<vector<char>> maze; // maze[y][x]
vector<vector<bool>> visited;

void floodfill(int y, int x) {
    if(y<0 or x<0 or y>=n or x>=m or visited[y][x] or maze[y][x] == '#') return;
    visited[y][x] = true;
    floodfill(y-1, x);
    floodfill(y, x-1);
    floodfill(y+1, x);
    floodfill(y, x+1);
}

void solve() {
    cin >> n >> m;
    maze.resize(n, vector<char>(m));
    for(auto &x: maze) {
        for(auto &y: x) cin >> y;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(maze[i][j] == 'B') {
                if((i>0 and maze[i-1][j] == 'G') ||
                    (j>0 and maze[i][j-1] == 'G') ||
                    (i<n-1 and maze[i+1][j] == 'G') || 
                    (j<m-1 and maze[i][j+1] == 'G')) {
                        cout << "No" << endl;
                        return;
                    }
                if(i>0 and maze[i-1][j] == '.') maze[i-1][j] = '#';
                if(j>0 and maze[i][j-1] == '.') maze[i][j-1] = '#';
                if(i<n-1 and maze[i+1][j] == '.') maze[i+1][j] = '#';
                if(j<m-1 and maze[i][j+1] == '.') maze[i][j+1] = '#';
            }
        }
    }
    visited.resize(n, vector<bool>(m));
    floodfill(n-1, m-1);
    /*
    for(auto &x: maze) {
        for(auto &y: x) cout << y;
        cout << endl;
    }
    for(auto &x: visited) {
        for(auto y: x) cout << y;
        cout << endl;
    }
    */
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(maze[i][j] == 'G' and !visited[i][j]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        solve();
        visited.clear();
        maze.clear();
    }
}