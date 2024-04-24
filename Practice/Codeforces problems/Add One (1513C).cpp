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

vector<ll> dp;
ll n, m; 

void solve() {
    cin >> n >> m;
    ll sol = 0;
    while(n) {
        ll cur = n%10;
        n/=10;
        sol += ((m+cur<10)?1:dp[m+cur-10]);
        sol %= MOD;
    }

    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp.resize(2e5+1);
    for(int i=0; i<9; i++) dp[i] = 2;
    dp[9] = 3;
    for(int i=10; i<=2e5; i++) dp[i] = (dp[i-9] + dp[i-10])%MOD;

    int t; cin >> t;
    while(t--) solve();   
}