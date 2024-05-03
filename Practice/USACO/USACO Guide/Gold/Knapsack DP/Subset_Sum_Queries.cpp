#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 998244353

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> dp(1e4);
    dp[0] = 1;

    while(n--) {
        char sgn; ll b;
        cin >> sgn >> b;
        if(sgn=='+') {
            for(int i=k; i>=b; i--) dp[i] = (dp[i]+dp[i-b])%MOD;
        }
        else {
            for(int i=b; i<=k; i++) dp[i] = (dp[i]-dp[i-b]+MOD)%MOD;
        }
        cout << dp[k] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}   