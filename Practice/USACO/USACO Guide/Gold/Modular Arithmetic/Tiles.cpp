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
#define MOD 998244353

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int w, h; cin >> w >> h;
    ll sol = 1; // conjecture: 2^r * 2^h
    for(int i=0; i<w+h; i++) sol = (sol*2)%MOD;
    cout << sol << endl;
}