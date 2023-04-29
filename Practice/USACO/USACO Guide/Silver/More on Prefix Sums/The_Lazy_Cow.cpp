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
    ifstream fin("lazy.in");
    ofstream fout("lazy.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; fin >> n >> k;
    vector<vector<int>> grid(n+1, vector<int> (n+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int t; fin >> t;
            grid[i][j] = grid[i][j-1] + t;
        }
    }
    int sol = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int cur = 0;
            for(int l=-k; l<=k; l++) {
                if(i+l<1 or i+l>n) continue;
                cur += (grid[i+l][min(n, j+k-abs(l))] - grid[i+l][max(1, j-k+abs(l))-1]);
            }

            sol = max(sol, cur);
        }
    }


    fout << sol << endl;
}