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
    
    int n; cin >> n;
    // every 2x2 grid has to contain atleast 2 cows and no 2 cows can be at the same position
    vector<vector<int>> grid(n, vector<int> (n));
    for(auto &x: grid) {
        for(auto &y: x) cin >> y;
    }
    int rows = 0, columns = 0;
    for(int i=0; i<n; i++) {
        int sum[2]{};
        for(int j=0; j<n; j++) {
            sum[j%2] += grid[i][j];
        }
        rows += max(sum[0], sum[1]);
    }
    for(int i=0; i<n; i++){
        int sum[2]{};
        for(int j=0; j<n; j++) {
            sum[j%2] += grid[j][i];
        }
        columns += max(sum[0], sum[1]);
    }
    cout << max(rows, columns) << endl;
}  