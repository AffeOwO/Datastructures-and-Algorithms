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
    ll n; cin >> n;
    vector<ll> dp(n+1, 2e9);
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        int cur = i;
        while(cur) {
            dp[i] = min(dp[i], dp[i-cur%10]+1);
            cur /= 10;
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}