#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    // masha first maxi, oly second mini
    int n; cin >> n;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    vector<ll> pref(n+1);
    for(int i=1; i<=n; i++) pref[i] = pref[i-1] + (nums[i-1]%2);
    ll cur = 0;
    for(ll k=1; k<=n; k++) {
        // masha = k+1/2 times; oly = k/2 times
        cur += nums[k-1]; // total sum
        if(k==1) cout << nums[0] << " ";
        else {
            int temp = pref[k]/3;
            if(pref[k]%3==1) temp++;

            cout << cur-temp << " ";
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