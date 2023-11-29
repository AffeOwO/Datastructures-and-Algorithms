#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    string s; cin >> s;
    int q; cin >> q;
    int xor0 = 0, xor1 = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '0') xor0 ^= nums[i];
        else xor1 ^= nums[i];
    }
    vector<int> pref(n+1);
    for(int i=1; i<=n; i++) {
        pref[i] = pref[i-1]^nums[i-1];
    }

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l, r; cin >> l >> r;
            // flip all s[i] such that l <= i <= r -> xor all bits with 1 in interval
            int temp = pref[r]^pref[l-1];
            xor0 ^= temp;
            xor1 ^= temp;
        }
        else {
            int g; cin >> g;
            // compute the xor of all nums[i] such that s[i]=g
            if(g==0) cout << xor0 << " ";
            else cout << xor1 << " ";
        }
    }
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}