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
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(auto &v: coins) cin >> v;
    sort(all(coins));
    vector<int> dp(x+1);
    
    for(int i=1; i<=x; i++) {
        for(int k=0; k<n; k++) {
            if(i==coins[k]) dp[i] = 1;
            if(i>coins[k] and dp[i-coins[k]]!=0) {
                if(dp[i]!=0) dp[i] = min(dp[i], dp[i-coins[k]]+1);
                else dp[i] = dp[i-coins[k]]+1;
            }
        }
    }
    //for(auto &x: dp) cout << x << " ";

    if(dp[x]==0) cout << -1 << endl;
    else cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}