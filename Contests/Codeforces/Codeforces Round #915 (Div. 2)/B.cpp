#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;

int sol;
/*
void dfs(int node, int cur) {
    if(visited[node]) return;
    visited[node] = true;
    cur += (edges[node].size()-(node!=0))/2;
    for(auto &x: edges[node]) dfs(x, cur);
    //cout << cur << endl;
    sol = max(sol, cur);
}*/

void solve() {
    int n; cin >> n;
    edges.clear();
    edges.resize(n);
    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }
    sol = 0;
    for(auto &x: edges) sol += x.size()==1;
    sol = (sol/2) + sol%2;

    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}