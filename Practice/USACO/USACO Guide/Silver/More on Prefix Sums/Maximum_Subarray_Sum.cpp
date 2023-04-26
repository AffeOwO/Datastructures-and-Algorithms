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
    ll sol = 0, cur = 0;
    for(int i=0; i<n; i++) {
        int t; cin >> t;
        cur += t;
        if(i == 0 or cur > sol) sol = cur;
        if(cur<0) cur = 0;
    }
    cout << sol << endl;
}