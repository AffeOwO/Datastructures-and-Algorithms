#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

struct segtree {
    int size = 1;
    vector<ll> sums;
    void init(int n) {
        while(size<n) size*=2;
        sums.resize(2*size-1);
    }

    void set(int i, ll v, int x, int lx, int rx) {
        if(rx==lx+1) {
            sums[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void set(int i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if(lx>=r or rx<=l) return 0;
        if(lx>=l and rx<=r) return sums[x];
        int m = (lx+rx)/2;
        ll v1 = sum(l, r, 2*x+1, lx, m);
        ll v2 = sum(l, r, 2*x+2, m, rx);
        return v1+v2;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    segtree st;
    st.init(n);

    for(int i=0; i<m; i++) {
        int t; cin >> t;
        if(t==1) {
            ll l, r, v; cin >> l >> r >> v;
            st.set(l, v);
            if(r!=n) st.set(r, -1*v);
        }
        else {
            ll i; cin >> i;
            cout << st.sum(0, i+1) << endl;
        }
    }
}