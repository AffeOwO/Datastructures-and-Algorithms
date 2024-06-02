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

    ll sum(int i, int x, int lx, int rx) {
        if(lx>=i) return 0;
        if(i>=rx) return sums[x];
        int m = (lx+rx)/2;
        return sum(i, 2*x+1, lx, m)+sum(i, 2*x+2, m, rx);
    }

    ll sum(int i) {
        return sum(i, 0, 0, size);
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<ll>  nums(n);
    segtree st;
    st.init(n);
    for(auto &x: nums) cin >> x;
    
    while(q--) {
        int t; cin >> t;
        if(t==1) {
            ll l, r, v; cin >> l >> r >> v;
            st.set(l-1, v); 
            if(r!=n) st.set(r, -1*v);
        }
        else {
            int i; cin >> i;
            cout << nums[i-1]+st.sum(i) << endl;
        }
    }
}