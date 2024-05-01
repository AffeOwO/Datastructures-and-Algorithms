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

vector<vector<int>> clo;
int m, c, mini; 

void solve() {
    mini = 0;
    cin >> m >> c;
    clo.resize(c);
    for(auto &x: clo) {
        int k; cin >> k;
        x.resize(k);
        for(auto &y: x) cin >> y;
        sort(all(x));
        mini += x[0];
    }
    if(mini>m) {
        cout << "no solution" << endl; 
        return;
    }

    vector<vector<bool>> dp(c, vector<bool>(m+1));
    for(auto &x: clo[0]) dp[0][x] = true;
    for(int i=1; i<c; i++) {
        for(int j=0; j<=m; j++) {
            if(dp[i-1][j]) {
                for(auto &x: clo[i]) {
                    if(j+x<=m) dp[i][j+x] = true;
                }
            }
        }
    }
    int sol = 0;
    for(int i=0; i<=m; i++) {
        if(dp[c-1][i]) sol = i;
    }
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}