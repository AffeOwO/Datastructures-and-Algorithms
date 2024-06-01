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

    void set(int i, int x, int lx, int rx) {
        if(rx==lx+1){
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

    int sum(int l, int r, int x, int lx, int rx) {
        if(rx<=l or lx>=r) return 0;
        if(rx<=r and lx>=l) return sums[x];
        int m = (lx+rx)/2;
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
    vector<int> nums(2*n);
    segtree st;
    st.init(2*n);
    map<int, int> tmp;
    for(int i=0; i<2*n; i++) {
        cin >> nums[i];
        if(!tmp.count(nums[i])) tmp[nums[i]] = i;
    }
    
    vector<int> sol(n);

    for(int i=0; i<2*n; i++) {
        if(i>tmp[nums[i]]) {
            sol[nums[i]-1] = st.sum(tmp[nums[i]], i);
            st.set(tmp[nums[i]]);
        }
    }
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}