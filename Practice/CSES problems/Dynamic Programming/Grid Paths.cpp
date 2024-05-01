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
    vector<vector<char>> mat(n, vector<char>(n));
    for(auto &x: mat) {
        for(auto &y: x) cin >> y;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    dp[0][1] = 1; // to get dp[1][1] to 1
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(mat[i-1][j-1]!='*') dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    cout << dp[n][n] << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}