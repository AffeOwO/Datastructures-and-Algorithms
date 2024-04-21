#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, m;
vector<vector<int>> edges1, edges2;
pair<int, int> maxi = {0, 0};
 
void dfs1(int node, int prev, int dist) {
    if(dist>maxi.first) maxi = {dist, node};
    for(auto &x: edges1[node]) {
        if(x==prev) continue;
        dfs1(x, node, dist+1);
    }
}
 
void dfs2(int node, int prev, int dist) {
    if(dist>maxi.first) maxi = {dist, node};
    for(auto &x: edges1[node]) {
        if(x==prev) continue;
        dfs2(x, node, dist+1);
    }
}
 
void solve() {
    cin >> n;
    // sol = (dia1 + 1)/2 + (dia2 + 1)/2 + 1
    edges1.resize(n);
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges1[a].push_back(b);
        edges1[b].push_back(a);
    }
    cin >> m;
    edges2.resize(m);
    for(int i=1; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges2[a].push_back(b);
        edges2[b].push_back(a);
    }
 
    int dia1, dia2;
    dfs1(0, 0, 0);
    dfs1(maxi.second, maxi.second, 0);
    dia1 = maxi.first;
    maxi = {0, 0};
    dfs2(0, 0, 0);
    dfs2(maxi.second, maxi.second, 0);
    dia2 = maxi.first;
    cout << max({dia1, dia2, (dia1+1)/2 + (dia2+1)/2 + 1}) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}