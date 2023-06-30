#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int m;
    cin >> m;
    vector<vector<char>> c(2, vector<char>(m));
    for (int j = 0; j < 2; j++){
        for (int k = 0; k < m; k++){
            cin >> c[j][k];
        }
    }
    vector<bool> ok(2, true);
    int cnt = 0;
    for (int j = 0; j < m; j++){
        if(c[0][j] == 'B' && c[1][j] == 'B') cnt++;
        if(c[0][j] == 'W') ok[cnt % 2] = false;
        if(c[1][j] == 'W') ok[1 - cnt % 2] = false;
    }
    if(ok[0] || ok[1]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}