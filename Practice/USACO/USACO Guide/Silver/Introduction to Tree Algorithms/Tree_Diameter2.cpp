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

int n;
vector<vector<int>> edges;
vector<int> toLeaf, par;

void dfs(int node, int prev) {
    par[node] = prev;
    for(auto &x: edges[node]) {
        if(x!=prev) {
            dfs(x, node);
            toLeaf[node] = max(toLeaf[node], 1+toLeaf[x]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    edges.resize(n); toLeaf.resize(n); par.resize(n);

    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // node 1 (0) is root
    dfs(0, 0);
    // for(auto &x: toLeaf) cout << x << endl;
    int sol = 0;

    for(int i=0; i<n; i++) {
        if((i!=0 and edges[i].size()<3) or n == 1) continue;
        vector<int> cur;
        for(auto &x: edges[i]) {
            if(x==par[i]) continue;
            cur.push_back(toLeaf[x]);
        }
        sort(all(cur));
        if(i==0 and cur.size()==1) sol = cur[0]+1;
        else sol = max(sol, cur.back()+cur[cur.size()-2]+2);
    }

    cout << sol << endl;
}