#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

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

    int n, q; cin >> n >> q;
    // forest is 1-indexed
    vector<vector<int>> forest(n+1, vector<int> (n+1));
    // prefix sum, how should i implement it?
    for(int i=1; i<=n; i++) {
        string idk; cin >> idk;
        for(int j=1; j<=n; j++) {
            forest[i][j] = forest[i][j-1] + forest[i-1][j] - forest[i-1][j-1] + (idk[j-1] == '*');
        }
    }
    for(int i=0; i<q; i++) {
        int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
        cout << forest[y2][x2] - (forest[y2][x1-1] + forest[y1-1][x2]) + forest[y1-1][x1-1] << endl;
    }
}