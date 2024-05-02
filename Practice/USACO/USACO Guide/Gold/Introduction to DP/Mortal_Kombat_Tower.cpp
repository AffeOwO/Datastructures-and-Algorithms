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

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x; // 0 = easy; 1 = hard

    vector<vector<int>> dp(2, vector<int>(n+1, 1e9));
    dp[1][0] = 0;

    for(int i=0; i<n; i++) {
        dp[0][i+1] = min(dp[0][i+1], dp[1][i] + nums[i]);
        dp[1][i+1] = min(dp[1][i+1], dp[0][i]);
        if(i+2<=n) {
            dp[0][i+2] = min(dp[0][i+2], dp[1][i] + nums[i] + nums[i+1]);
            dp[1][i+2] = min(dp[1][i+2], dp[0][i]);
        }
    }

    cout << min(dp[0][n], dp[1][n]) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}