#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> vec(n), pref(n), suff(n);
    for(auto &x: vec) cin >> x;
    for(int i=0; i<n; i++) {
        pref[i] = vec[i]+i;
        suff[i] = vec[i]-i;
    }
    for(int i=1; i<n; i++) pref[i] = max(pref[i], pref[i-1]);
    for(int i=n-2; i>=0; i--) suff[i] = max(suff[i], suff[i+1]);
    int sol = 0;

    for(int i=1; i<n-1; i++) sol = max(sol, vec[i]+pref[i-1]+suff[i+1]);

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