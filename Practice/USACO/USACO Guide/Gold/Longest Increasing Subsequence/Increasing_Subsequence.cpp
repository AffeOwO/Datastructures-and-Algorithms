#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> nums(n), dp(n, 2e9);
    for(auto &x: nums) cin >> x;
    dp[0] = nums[0];
    for(int i=1; i<n; i++) {
        int l = 0, r = n-1, m;
        while(l<=r) {
            m = (l+r)/2;
            if(dp[m]>=nums[i]) r = m-1;
            else l = m+1;
        }
        // r+1
        dp[r+1] = nums[i];
    }
    for(int i=n-1; i>=0; i--) {
        if(dp[i] != 2e9) {
            cout << i+1 << endl;
            break;
        }
    }
}