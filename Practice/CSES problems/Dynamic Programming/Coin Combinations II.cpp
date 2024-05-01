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
    vector<ll> coins(n);
    for(auto &c: coins) cin >> c;
    sort(all(coins));

    vector<ll> dp(x+1);
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=1; j<=x; j++) {
            if(coins[i]>j) continue;
            dp[j] = (dp[j] + dp[j-coins[i]])%MOD;
        }
    }
    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}