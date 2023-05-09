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

void solve() {
    int n, m, i, j; cin >> n >> m >> i >> j;
    // n*m grid and anton is in cell (i, j)

    // conjecture: throwing the jojo in any cell besides a cornor is suboptimal
    // shortest path from (x, y) to (x2, y2) is (abs(x-x2))+abs((y-y2))
    // chooses tha corner which has the biggest distance and then the opposite corner
    map<int, vector<int>> distances;
    
    int idk = max({i-1+j-1, i-1+abs(m-j), abs(n-i)+j-1, abs(n-i)+abs(m-j)});
    
    if(idk == i-1+j-1 or idk==abs(n-i)+abs(m-j)) {
        cout << "1 1 " << n << " " << m;
    }
    else{
        cout << 1 << " " << m << " " << n << " " << 1 ;
    }
    

    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}