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
    vector<int> sums;
    void init(int n) {
        while(size<n) size*=2;
        sums.resize(2*size-1);
    }

    void build(int n, int x, int lx, int rx) {
        if(rx==lx+1) {
            if(lx<n) sums[x] = 1;
            return;
        }
        int m = (lx+rx)/2;
        build(n, 2*x+1, lx, m);
        build(n, 2*x+2, m, rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void build(int n) {
        build(n, 0, 0, size);
    }

    void set(int i, int x, int lx, int rx) {
        if(rx==lx+1) {
            sums[x] = 0;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) set(i, 2*x+1, lx, m);
        else set(i, 2*x+2, m, rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void set(int i) {
        set(i, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if(lx>=r or rx<=l) return 0;
        if(lx>=l and rx<=r) return sums[x];
        int m=(lx+rx)/2;
        int v1 = sum(l, r, 2*x+1, lx, m);
        int v2 = sum(l, r, 2*x+2, m, rx);
        return v1+v2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> nums(n), sol(n);
    segtree st;
    for(auto &x: nums) cin >> x;
    st.init(n);
    st.build(n);


    for(int i=n-1; i>=0; i--) {
        int l = 0, r = n-1, m;
        while(l<=r) {
            m = (l+r)/2;
            if(st.sum(m, n)<=nums[i]) r=m-1;
            else l=m+1;
        }
        sol[i] = r+1;
        if(r>=0 and st.sum(r, n)==nums[i]) sol[i]--;
        st.set(sol[i]-1);
    }

    for(auto &x: sol) cout << x << " ";
    cout << endl;
}