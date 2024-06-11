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

struct segtree {
    int size = 1;
    vector<int> sums;
    void init(int n) {
        while(size<n) size*=2;
        sums.reserve(2*size-1);
    }

    void build(int n, int x, int lx, int rx) {
        if(rx==lx+1) {
            if(n>lx) sums[x] = 1;
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

    int sum(int r, int x, int lx, int rx) {
        if(lx>=r) return 0;
        if(rx<=r) return sums[x];
        int m = (lx+rx)/2;
        int v1 = sum(r, 2*x+1, lx, m);
        int v2 = sum(r, 2*x+2, m, rx);
        return v1+v2;
    }

    int sum(int r) {
        return sum(r, 0, 0, size); 
    }
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    segtree seg;
    seg.init(n);
    seg.build(n);

    for(int i=0; i<n; i++) {
        int p; cin >> p;
        int l = 0, r = n, m;
        // if < -> l = m+1
        while(l<=r) {
            m = (l+r)/2;
            if(seg.sum(m+1)<p) l = m+1;
            else r = m-1;
        }
        cout << a[l] << " ";
        seg.set(l);
    }   
}