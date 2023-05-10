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
    ll x; cin >> x;
    // maybe bruteforce bin search?
    ll b;
    for(ll a=1; a<=cbrt(x); a++) {
        // now bin search
        b = cbrt(x - pow(a, 3));
        if(b==0) continue;
        if(pow(b, 3) == x-pow(a, 3)) {
            cout << "YES" << endl;
            return;
        } 
    }
    cout << "NO" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}