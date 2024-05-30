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
    vector<int> minarr;
    void init(int n) {
        while(size<n) size *= 2;
        minarr.resize(2*size-1);
    }

    void build(vector<int> &arr, int x, int lx, int rx) {
        if(rx==lx+1) {
            if(lx<(int)arr.size()) minarr[x] = arr[lx];
            return;
        }
        int m = (lx+rx)/2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        minarr[x] = min(minarr[2*x+1], minarr[2*x+2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx==lx+1) {
            minarr[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        minarr[x] = min(minarr[2*x+1], minarr[2*x+2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int mini(int l, int r, int x, int lx, int rx) {
        if(lx>=r or rx<=l) return 2e9;
        if(lx>=l and rx<=r) return minarr[x];
        int m = (lx+rx)/2;
        int v1 = mini(l, r, 2*x+1, lx, m);
        int v2 = mini(l, r, 2*x+2, m, rx);
        return min(v1, v2);
    }

    int mini(int l, int r) {
        return mini(l, r, 0, 0, size);
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
            cout << st.mini(a, b) << endl;
        }
    }
}