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
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; fin >> n >> m;
    edges.resize(n);
    int addi = 0;
    for(int i=0; i<m; i++) {
        char c; fin >> c;
        int a, b; fin >> a >> b;
        a--; b--;
        if(c=='D') {
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        else {
            edges.push_back({});
            edges[a].push_back(n+addi);
            edges[b].push_back(n+addi);
            edges[n+addi].push_back(a);
            edges[n+addi].push_back(b);
            addi++;
        }
    }
    // 2^(amount of components);
    visited.resize(n+addi);
    int sol = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            sol++;
            dfs(i);
        }
    }
    if(sol==1 and visited.size()%2==1) {
        fout << 0 << endl;
        return 0;
    }
    fout << 1;
    for(int i=0; i<sol; i++) fout << 0;
    fout << endl;
}