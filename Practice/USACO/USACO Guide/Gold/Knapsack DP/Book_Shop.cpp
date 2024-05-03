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
    ll n, x; cin >> n >> x;
    vector<ll> h(n), s(n);
    for(auto &y: h) cin >> y;
    for(auto &y: s) cin >> y;
    
    vector<vector<ll>> dp(n+1, vector<ll>(x+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=x; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-h[i-1]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-h[i-1]]+s[i-1]);
        }
    }
    cout << dp[n][x] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}