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
        while(size<n) size *= 2;
        sums.resize(2*size-1);
    }

    // interval is [lx, rx)
    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx==lx+1) {
            if((int) a.size()>lx) sums[x] = a[lx];
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx==lx+1) {
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) {
            set(i, v, 2*x+1, lx, m);
        }
        else {
            set(i, v, 2*x+2, m, rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if(lx>=r or l>=rx) return 0;
        if(l<=lx and rx<=r) return sums[x]; 
        int m = (lx+rx)/2;
        ll s1 = sum(l, r, 2*x+1, lx, m);
        ll s2 = sum(l, r, 2*x+2, m, rx);
        return s1+s2;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> nums(n);
    segtree st;
    st.init(n);
    for(auto &x: nums) cin >> x;
    st.build(nums);

    while(m--) {
        int t, a, b; cin >> t >> a >> b;
        if(t==1) {
            st.set(a, b);
        }
        else {
            cout << st.sum(a, b) << endl;
        }
    }
}