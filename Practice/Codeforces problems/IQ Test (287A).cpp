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
    
    vector<vector<char>> idk(4, vector<char> (4));
    for(auto &x: idk) {
        for(auto &y: x) cin >> y;
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int cur = (idk[i][j] == '#') + (idk[i+1][j] == '#') + (idk[i][j+1] == '#') + (idk[i+1][j+1] == '#');
            if(cur <= 1 or cur >= 3) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}