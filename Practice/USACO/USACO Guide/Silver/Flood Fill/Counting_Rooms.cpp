#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, m; 
vector<vector<bool>> visited;
vector<vector<char>> building;

void dfs(int y, int x) {
    if(visited[y][x] or building[y][x] == '#') return;
    visited[y][x] = true;
    if(y>0) dfs(y-1, x);
    if(x>0) dfs(y, x-1);
    if(y<n-1) dfs(y+1, x);
    if(x<m-1) dfs(y, x+1);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    building.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m));
    for(auto &x: building) {
        for(auto &y: x) cin >> y;
    }
    int rooms = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] and building[i][j] != '#') {
                rooms++;
                dfs(i, j);
            }
        }
    }


    cout << rooms << endl;
}