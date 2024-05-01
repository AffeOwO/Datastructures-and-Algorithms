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

    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for(auto &c: coins) cin >> c;
    vector<ll> dp(x+1); dp[0] = 1;
    for(int i=1; i<=x; i++) {
        for(auto &c: coins) {
            if(i>=c and dp[i-c]!=0) dp[i]=(dp[i]+dp[i-c])%MOD; 
        }
    }


    cout << dp[x] << endl;   
}