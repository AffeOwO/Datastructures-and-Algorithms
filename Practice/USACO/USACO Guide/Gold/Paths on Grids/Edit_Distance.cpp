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

int n, m;
string s1, s2; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    n = s1.size(); m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0 and j==0) continue;
            if(i==0) {
                dp[i][j] = dp[i][j-1]+1;
            }
            else if(j==0) {
                dp[i][j] = dp[i-1][j]+1;
            }
            else {
                dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+1-(s1[i-1]==s2[j-1])});
            }
        }
    }


    cout << dp[n][m] << endl;
}