#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<pair<int, int>>> edges;
vector<bool> visited;
int cnt, cur;

void dfs(int node) {
    if(visited[node]) return;
    cnt++;
    visited[node] = true;
    for(auto &x: edges[node]) {
        if(x.second>=cur) dfs(x.first);
    }
}

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; fin >> n >> q;
    // n videos posted already
    edges.resize(n);
    for(int i=0; i<n-1; i++) {
        int p, q, r; fin >> p >> q >> r;
        p--; q--;
        edges[p].push_back({q, r});
        edges[q].push_back({p, r});
    }

    for(int i=0; i<q; i++) {
        int k, v; fin >> k >> v;
        v--;
        // how many videos will be suggested after video v
        visited.resize(n);
        cnt = -1; cur = k;

        dfs(v);
        //cout << cnt << " " << cur << " " << k << " " << v << endl;

        fout << cnt << endl;
        visited.clear();
    }
}