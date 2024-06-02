#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

struct DSU {
    vector<pair<int, int>> par;
    void init(int n) {
        par.resize(n);
        for(int i=0; i<n; i++) par[i] = make_pair(i, 1);
    }

    int get(int v) {
        if(par[v].first==v) return v;
        else return (par[v].first=get(par[v].first));
    }

    void un(int u, int v) {
        u = get(u); v = get(v);
        if(u==v) return;
        if(par[u].second<par[v].second) swap(u, v);
        par[u].second += par[v].second;
        par[v].first = u;
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    DSU dsu;
    dsu.init(n);


    while(q--) {
        int t, u, v; cin >> t >> u >> v;
        if(t==0) {
            dsu.un(u, v);
        }
        else {
            if(dsu.get(u)==dsu.get(v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }   
}