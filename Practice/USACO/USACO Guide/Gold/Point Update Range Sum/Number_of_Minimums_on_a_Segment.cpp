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
    vector<pair<int, int>> minarr;
    void init(int n) {
        while(size<n) size *= 2;
        minarr.resize(2*size-1);
    }

    pair<int, int> comp(pair<int, int> p1, pair<int, int> p2) {
        if(p1.first==p2.first) return make_pair(p1.first, p1.second+p2.second);
        else if(p1.first<p2.first) return p1;
        else return p2;
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx==lx+1) {
            if(lx<a.size()) minarr[x] = make_pair(a[lx], 1);
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        minarr[x] = comp(minarr[2*x+1], minarr[2*x+2]);
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx==lx+1) {
            minarr[x] = make_pair(v, 1);
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        minarr[x] = comp(minarr[2*x+1], minarr[2*x+2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair<int, int> mini(int l, int r, int x, int lx, int rx) {
        if(rx<=l or lx>=r) return make_pair(2e9, -1);
        if(rx<=r and lx>=l) return minarr[x];
        int m = (lx+rx)/2;
        pair<int, int> p1 = mini(l, r, 2*x+1, lx, m);
        pair<int, int> p2 = mini(l, r, 2*x+2, m, rx);
        if(p1.first==p2.first) return make_pair(p1.first, p1.second+p2.second);
        else if(p1.first<p2.first) return p1;
        else return p2;
    }

    pair<int, int> mini(int l, int r) {
        return mini(l, r, 0, 0, size);
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> nums(n);
    segtree st;
    st.init(n);
    for(auto &x: nums) cin >> x;
    st.build(nums);

    //for(auto &x: st.minarr) cout << x.first << " " << x.second << endl;

    while(m--) {
        int t, a, b; cin >> t >> a >> b;
        if(t==1) st.set(a, b);
        else {
            pair<int, int> tmp = st.mini(a, b);
            cout << tmp.first << " " << tmp.second << endl;
        }
    }
}