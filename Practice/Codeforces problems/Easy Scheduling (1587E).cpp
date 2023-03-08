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

void solve() {
    ll h, p; cin >> h >> p;
    ll sol = 0, remain = pow(2, h) - 1;

    while(true) {
        ll temp  = pow(2, sol);
        if(temp>p) break;
        remain -= temp;
        sol++;
        if(remain <= 0) {
            cout << h << endl;
            return;
        }
    }
    sol += remain/p;
    if(remain%p != 0) sol++;

    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }
}