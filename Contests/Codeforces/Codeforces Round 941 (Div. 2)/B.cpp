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
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m)); // 0 = B, 1 = W
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char cur; cin >> cur;
            if(cur=='B') matrix[i][j] = 0;
            else matrix[i][j] = 1;
        }
    }

    if(matrix[0][0] == matrix[n-1][m-1] or matrix[n-1][0] == matrix[0][m-1]) {
        cout << "YES" << endl;
        return;
    }

    // try to change (0, 0)
    pair<bool, bool> tmp = {false, false};
    for(int i=1; i<n; i++) {
        if(matrix[i][0] != matrix[0][0]) tmp.first = true;
    }
    for(int j=1; j<m; j++) {
        if(matrix[0][j] != matrix[0][0]) tmp.second = true;
    }
    if(tmp.first and tmp.second) {
        cout << "YES" << endl;
        return;
    }

    tmp = {false, false};
    for(int i=0; i<n-1; i++) {
        if(matrix[i][m-1] != matrix[n-1][m-1]) tmp.first = true;
    }
    for(int j=0; j<m-1; j++) {
        if(matrix[n-1][j] != matrix[n-1][m-1]) tmp.second = true;
    }
    if(tmp.first and tmp.second) {
        cout << "YES" << endl;
        return;
    }

    tmp = {false, false};
    for(int i=0; i<n-1; i++) {
        if(matrix[i][0] != matrix[n-1][0]) tmp.first = true;
    }
    for(int j=1; j<m; j++) {
        if(matrix[n-1][j] != matrix[n-1][0]) tmp.second = true;
    }
    if(tmp.first and tmp.second) {
        cout << "YES" << endl;
        return;
    }

    tmp = {false, false};
    for(int i=1; i<n; i++) {
        if(matrix[i][m-1] != matrix[0][m-1]) tmp.first = true;
    }
    for(int j=0; j<m-1; j++) {
        if(matrix[0][j] != matrix[0][m-1]) tmp.second = true;
    }
    if(tmp.first and tmp.second) {
        cout << "YES" << endl;
        return;
    }


    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}