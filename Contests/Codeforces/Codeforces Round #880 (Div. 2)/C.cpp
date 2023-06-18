#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int a, b, c; cin >> a >> b >> c;  // <=k; A has a digits, B has b digits, C has c digits (positive and no leading zeroes)
    ll k; cin >> k;
    if(a>c or b>c) {
        cout << -1 << endl;
        return;
    }
    // A + B = C, find the lexicographically smallest equation
    /*
    - how many ways are there for A+B=C ?
    
    */
    
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}