#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int cur_comp, cur_max = 1;

struct DSU {
    vector<pair<int, int>> par;
    void init(int n) {
        par.resize(n);
        for(int i=0; i<n; i++) par[i] = make_pair(i, 1);
    }

    int get(int x) {
        if(par[x].first==x) return x;
        else return (par[x].first = get(par[x].first));
    }

    void un(int u, int v) {
        u = get(u); v = get(v);
        if(u==v) return;
        if(par[u].second<par[v].second) swap(u, v);
        par[u].second += par[v].second;
        cur_max = max(cur_max, par[u].second);
        par[v].first = u;
        cur_comp--;
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    cur_comp = n;
    DSU dsu;
    dsu.init(n);
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        dsu.un(u-1, v-1);
        cout << cur_comp << " " << cur_max << endl;
    }
}