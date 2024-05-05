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
    int n, k; cin >> n >> k;

    vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(505, vector<bool>(505)));
    dp[0][0][0] = 1;
    for(int i=1; i<=n; i++) {
        int cur = i%2, last = 1-cur;
        int x; cin >> x;
        for(int j=0; j<=k; j++) {
            for(int h=0; h<=j; h++) {
                dp[cur][j][h] = dp[last][j][h];
                if(j>=x) {
                    if(dp[last][j-x][h]) dp[cur][j][h] = true;
                    if(h>=x) {
                        if(dp[last][j-x][h-x]) dp[cur][j][h] = true;
                    }
                }
            }
        }
    }
    vector<int> sol;
    for(int i=0; i<=k; i++) {
        if(dp[n%2][k][i]) sol.push_back(i);
    }
    cout << sol.size() << endl;
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}