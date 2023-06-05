#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
set<int> cyclic;
vector<bool> visited;

void dfs(int node, vector<int> route) {
    if(visited[node] == true) {
        if(route[0] == node) {
            for(auto &x: route) cyclic.insert(x);
        }
        return;
    }
    route.push_back(node);
    visited[node] = true;
    for(auto &x: edges[node]) dfs(x, route);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    edges.resize(n);
    for(int i=0; i<k; i++) {
        int a, b, s_a, s_b; cin >> a >> b >> s_a >> s_b;
        a--; b--;
        if(s_a>s_b) edges[a].push_back(b); // player a wins
        else edges[b].push_back(a); // player b wins
    }
    vector<bool> temp(n);
    for(int i=0; i<n; i++) {
        vector<int> idk;
        visited = temp;
        dfs(i, idk);
    }

    cout << cyclic.size() << endl;
}