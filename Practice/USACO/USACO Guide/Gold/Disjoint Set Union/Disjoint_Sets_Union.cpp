#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

struct DSU {
    vector<pair<int, int>> a;
    void init(int n) {
        a.resize(n);
        for(int i=0; i<n; i++) a[i] = {i, 1};
    }

    int get(int u) {
        if(u==a[u].first) return u;
        return a[u].first = get(a[u].first);
    }

    void un(int u, int v) {
        u = get(u); v = get(v);
        if(u==v) return;
        if(a[u].second<a[v].second) swap(u, v);
        a[u].second += a[v].second;
        a[v].first = u;
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;   
    DSU dsu;
    dsu.init(n);

    while(m--) {
        string t; cin >> t;
        int u, v; cin >> u >> v;
        u--; v--;
        if(t=="union") {
            dsu.un(u, v);
        }
        else {
            if(dsu.get(u)==dsu.get(v)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}