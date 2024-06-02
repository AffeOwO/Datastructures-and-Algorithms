#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

char trash;

struct segtree{
    int size = 1;
    vector<int> sums;
    void init(int n) {
        while(size<n) size*=2;
        sums.resize(2*size-1);
    }

    void set(int i, int x, int lx, int rx) {
        if(rx==lx+1) {
            sums[x] = 1;
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

    int sum(int l, int x, int lx, int rx) {
        if(l>=rx) return 0;
        if(lx>=l) return sums[x];
        int m = (lx+rx)/2;
        return sum(l, 2*x+1, lx, m) + sum(l, 2*x+2, m, rx);
    }

    int sum(int l) {
        return sum(l, 0, 0, size);
    }
};

void solve() {
    ll n, sol = 0; cin >> n;
    segtree st;
    st.init(1e7+1);
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        sol += st.sum(v);
        st.set(v-1);
    }
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while(t--) solve();
}