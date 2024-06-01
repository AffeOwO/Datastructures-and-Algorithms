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

    void set(int i, int v, int x, int lx, int rx) {
        if(rx==lx+1) {
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if(lx>=r or rx<=l) return 0;
        if(lx>=l and rx<=r) return sums[x];
        int m = (lx+rx)/2;
        return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    segtree st;
    st.init(2*n);
    map<int, int> tmp;
    vector<int> sol(n), nums(2*n);
    for(int i=0; i<2*n; i++) {
        int x; cin >> x;
        nums[2*n-i-1] = x;
        if(!tmp.count(x)) {
            tmp[x] = i;
            st.set(i, 1);
        }
        else {
            st.set(tmp[x], -1);
            st.set(i, 1);
            sol[x-1] = st.sum(tmp[x]+1, i);
        }
    }
    

    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

/*
cout << endl;
    st.sums.clear();
    st.init(2*n);
    tmp.clear();
    for(int i=0; i<2*n; i++) {
        if(!tmp.count(nums[i])) {
            tmp[nums[i]] = i;
            st.set(i, 1);
        }
        else {
            st.set(tmp[nums[i]], -1);
            st.set(i, 1);
            sol[nums[i]-1] += st.sum(tmp[nums[i]]+1, i);
        }
        for(auto &x: st.sums) cout << x << " ";
        cout << endl;
    }
*/