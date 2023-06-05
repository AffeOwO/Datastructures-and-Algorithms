#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

// all 0-indexed
vector<bool> visited;
vector<vector<int>> components;
map<int, vector<int>> nodes;

void dfs(int node, int component) {
    if(visited[node] == true) return;
    visited[node] = true;
    components[component].push_back(node);
    for(auto x: nodes[node]) dfs(x, component);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m; // n nodes, m edges
    visited.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    int cur = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            components.push_back({});
            dfs(i, cur);
            cur++;
        }
    }
    cout << components.size()-1 << endl;
    for(int i=1; i<components.size(); i++) cout << components[0][0]+1 << " " << components[i][0]+1 << endl;
    // for output, node+1
}