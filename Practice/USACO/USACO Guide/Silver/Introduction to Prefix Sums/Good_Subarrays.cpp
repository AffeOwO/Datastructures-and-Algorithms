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
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> pref(n+1);
    for(int i=1; i<=n; i++) {
        pref[i] = pref[i-1] + s[i-1]-'0';
    }
    ll sol = 0;
    map<ll, ll> idk;
    for(int i=0; i<=n; i++) {
        sol += idk[pref[i]-i];
        idk[pref[i]-i]++;
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