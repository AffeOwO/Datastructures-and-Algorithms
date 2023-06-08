#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
vector<int> nodes;

int dfs(int node) {
    int cur = 0;
    for(auto &x: edges[node]) {
        cur += dfs(x)+1;
    }
    nodes[node] = cur;
    return cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    edges.resize(n);
    nodes.resize(n, -1);
    for(int i=1; i<n; i++) {
        int cur; cin >> cur;
        cur--;
        edges[cur].push_back(i);
    }
    dfs(0);
    for(auto &x: nodes) cout << x << " ";
    cout << endl;
}