#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
vector<int> subtrees;
vector<bool> visited;

int dfs(int node) {
    if(visited[node]) return 0;
    visited[node] = true;
    for(auto &x: edges[node]) subtrees[node] += dfs(x);
    return subtrees[node];
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    if(n%2==1) {
        cout << -1 << endl;
        return 0;
    }
    edges.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    subtrees.resize(n, 1);
    visited.resize(n);
    // let 0 be the root of the tree
    dfs(0);
    int sol = -1;
    for(auto &x: subtrees) {
        if(x%2==0) sol++;
    }
    cout << sol << endl;
}