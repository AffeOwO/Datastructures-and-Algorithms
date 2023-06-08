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
pair<int, int> maxi{0, 0}; // {distance, index}

void dfs(int node, int dist) {
    if(visited[node]) return;
    visited[node] = true;
    if(dist>maxi.first) maxi = {dist, node};
    for(auto &x: edges[node]) dfs(x, dist+1);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    edges.resize(n);
    visited.resize(n);
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, 0);
    visited.clear(); visited.resize(n);
    dfs(maxi.second, 0);
    cout << maxi.first << endl;
}