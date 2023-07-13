#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q; cin >> n >> m >> q; // n*m matrix (height = n; width = m); q queries
    // each square in the matrix is painted: 0=white; 1=blue
    // for every pair of blue squares, there is at most one path which connects both squares  -> acyclic
    /*
    example:
    11
    11
    -> not possible since there are 2 different paths from (0, 0) to (1, 1)
    */
    vector<vector<int>> mat(n, vector<int>(m));
    for(auto &x: mat) {
        string s; cin >> s;
        for(int i=0; i<m; i++) {
            x[i] = (s[i]-'0');
        }
    }

    vector<vector<pair<int, pair<int, int>>>> pref(n+1, vector<pair<int, pair<int, int>>> (m+1)); 
    // .first = nodes; .second.first = edges horizontal; .second.second = edges vertical
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            pref[i][j].first = pref[i-1][j].first + pref[i][j-1].first - pref[i-1][j-1].first + mat[i-1][j-1];
            pref[i][j].second.first = pref[i-1][j].second.first + pref[i][j-1].second.first - pref[i-1][j-1].second.first;
            pref[i][j].second.second = pref[i-1][j].second.second + pref[i][j-1].second.second - pref[i-1][j-1].second.second;
            if(i!=1 and mat[i-2][j-1] and mat[i-1][j-1]) pref[i][j].second.first++;
            if(j!=1 and mat[i-1][j-2] and mat[i-1][j-1]) pref[i][j].second.second++;  
        }   
    }

    for(int i=0; i<q; i++) {
        int x_1, y_1, x_2, y_2; cin >> x_1 >> y_1 >> x_2 >> y_2; // x = row; y = column (1-indexed) -> matrix[x-1][y-1]
        x_1--; y_1--;
        int nodes = pref[x_2][y_2].first + pref[x_1][y_1].first - pref[x_1][y_2].first - pref[x_2][y_1].first;
        int edges = pref[x_2][y_2].second.first + pref[x_2][y_2].second.second;
        edges -= (pref[x_1+1][y_2].second.first + pref[x_1][y_2].second.second);
        edges -= (pref[x_2][y_1+1].second.second + pref[x_2][y_1].second.first);
        //edges += pref[x_1][y_1].second.second + pref[x_1][y_1].second.first;
        edges += pref[x_1+1][y_1].second.first + pref[x_1][y_1+1].second.second;
        cout << nodes - edges << endl;
    }
}