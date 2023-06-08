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

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    for(auto &x: edges[node]) dfs(x);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    edges.resize(n);
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        cur--;
        edges[i].push_back(cur);
        edges[cur].push_back(i);
    }
    visited.resize(n);
    int sol = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            sol++;
            dfs(i);
        }
    }
    cout << sol << endl;
}