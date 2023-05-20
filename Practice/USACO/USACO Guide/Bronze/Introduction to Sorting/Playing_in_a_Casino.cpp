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
    int n, m; cin >> n >> m;
    // n cards where each card has m numbers written on it
    // p = players; p*(p-1)/2 games are played
    ll sol = 0;
    vector<vector<ll>> columns(m, vector<ll> (n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> columns[j][i];
        }
    }
    for(auto &x: columns) {
        sort(all(x));
        vector<ll> pref(n+1);
        for(int i=1; i<=n; i++) pref[i] = pref[i-1]+x[i-1];
        for(int i=0; i<n; i++) sol += (x[i]*i - pref[i]);        
    }
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