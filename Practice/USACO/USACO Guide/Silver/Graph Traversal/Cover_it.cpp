#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
vector<bool> visited; 
vector<int> sol1, sol2;

void dfs(int node, int color) {
    if(visited[node]) return;
    visited[node] = true;
    if(color==0) sol1.push_back(node+1);
    else sol2.push_back(node+1);
    for(auto &x: edges[node]) dfs(x, color^1);
}

void solve() {
    int n, m; cin >> n >> m;
    visited.resize(n);
    edges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    dfs(0, 0);
    cout << min(sol1.size(), sol2.size()) << endl;
    if(sol1.size()<sol2.size()) {
        for(auto &x: sol1) cout << x << " ";
    }
    else {
        for(auto &x: sol2) cout << x << " ";
    }
    cout << endl;

    sol1.clear(); sol2.clear();
    visited.clear();
    edges.clear();
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}