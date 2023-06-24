#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, m; cin >> n >> m; // tsondu, tenzing; tsondu starts
    ll ns = 0, ms = 0;
    for(int i=0; i<n; i++) {
        ll cur; cin >> cur;
        ns += cur;
    }
    for(int i=0; i<m; i++) {
        ll cur = 0; cin >> cur;
        ms += cur;
    }
    if(ns == ms) cout << "Draw" << endl;
    else if(ns>ms) cout << "Tsondu" << endl;
    else cout << "Tenzing" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}