#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges, revedges;
vector<bool> visited;
bool rev = false;

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    if(!rev) {
        for(auto &x: edges[node]) dfs(x);
    }
    else {
        for(auto &x: revedges[node]) dfs(x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    edges.resize(n);
    revedges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        revedges[b].push_back(a);
    }

    visited.resize(n);
    dfs(0);
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i+1 << endl;
            return 0;
        } 
    }
    rev = true;
    visited.clear(); visited.resize(n);
    dfs(0);
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            cout << "NO" << endl;
            cout << i+1 << " " << 1 << endl;
            return 0;
        } 
    }

    cout << "YES" << endl;
}