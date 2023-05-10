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
    ll a, b; cin >> a >> b;
    ll  x = a*(b-1), y = a, z = a*b;

    if(b==1) cout << "NO" << endl;
    else {
        if(b==2) {x*=3;z*=2;}
        cout << "YES" << endl;
        cout << x << " " << y << " " << z << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}