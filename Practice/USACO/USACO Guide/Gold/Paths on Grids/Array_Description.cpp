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

ll n, m; 
vector<ll> nums;

void solve() {
    cin >> n >> m;
    nums.resize(n);
    for(auto &x: nums) cin >> x;
    // nums[i]=0 -> unknown value
    // compute each interval

    vector<vector<ll>> dp(n, vector<ll>(m+2));
    if(nums[0]==0) {
        for(int i=1; i<=m; i++) dp[0][i] = 1;
    }
    else dp[0][nums[0]] = 1;
    for(int i=1; i<n; i++) {
        if(nums[i] == 0) {
            for(int j=1; j<=m; j++) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
        }
        else {
            dp[i][nums[i]] = (dp[i-1][nums[i]-1]+dp[i-1][nums[i]]+dp[i-1][nums[i]+1])%MOD;
        }
    }
    ll sol = 0;
    for(int i=1; i<=m; i++) sol = (sol+dp[n-1][i])%MOD;
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}