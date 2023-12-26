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
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    vector<ll> prefix_xor(n+1);
    for(int i=1; i<=n; i++) prefix_xor[i] = nums[i-1]^prefix_xor[i-1];
    if(prefix_xor[n]==0) {
        cout << "YES" << endl;
        return;
    }
    for(int i=1; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(prefix_xor[i]==(prefix_xor[j]^prefix_xor[i]) and prefix_xor[i]==(prefix_xor[n]^prefix_xor[j])) {
                cout << "YES" << endl;
                return;
            }
        }
    } 
    cout << "NO" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}