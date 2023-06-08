#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
vector<int> dist;
pair<int, int> maxi{0, 0}; // {max_dist, index}

void dfs(int node, int cnt) {
    if(dist[node] != -1) return;
    dist[node] = cnt;
    if(cnt>maxi.first) maxi = {cnt, node};
    for(auto &x: edges[node]) dfs(x, cnt+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // pi=3
    // diameter = longest path
    // circumference = 3*diameter
    int n; cin >> n; // nodes
    edges.resize(n);
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dist.resize(n, -1);
    dfs(0, 0);
    dist.clear(); dist.resize(n, -1);
    dfs(maxi.second, 0);
    cout << maxi.first*3 << endl;
}