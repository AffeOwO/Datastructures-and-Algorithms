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

ll calculate(ll a, ll b) {
    // solve this problem recursively
    // in this problem, 0^0 = 1 :/
    // f(a, b):
    // if b==0 -> 1
    // if a==0 -> 0
    // if b%2==0 -> f(a,b/2)*f(a,b/2)
    // if b%2==1 -> f(a,(b-1)/2)*f(a,(b+1)/2)
    if(b==1) return a;
    if(b%2==0) return (calculate(a, b/2) * calculate(a, b/2)) % MOD;
    if(b%2==1) return (((calculate(a, b/2) * calculate(a, b/2)) % MOD) * a) % MOD;

    return 1;
}

void solve() {
    ll a, b; cin >> a >> b;
    if(b == 0) {
        cout << 1 << endl;
        return;
    }
    else if(a==0) {
        cout << 0 << endl;
        return;
    }
    ll sol = calculate(a, b);
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}