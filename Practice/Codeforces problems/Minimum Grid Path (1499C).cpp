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
    // stand on (0; 0); reach (n; n)
    // move only to right and up
    vector<ll> costs(n);
    for(auto &x: costs) cin >> x;
    vector<ll> pref(n); pref[0] = costs[0];
    for(int i=1; i<n; i++) pref[i] = pref[i-1] + costs[i];

    pair<ll, ll> cur_min = {costs[0], costs[1]};
    ll sol = (n)*(cur_min.first+cur_min.second);
    
    for(int i=2; i<n; i++) {
        if(i%2==0) cur_min.first = min(cur_min.first, costs[i]);
        else cur_min.second = min(cur_min.second, costs[i]);

        int j = i+1;

        ll cur = pref[i];
        cur += cur_min.first*(n-j/2-j%2);
        cur += cur_min.second*(n-j/2);

        sol = min(sol, cur);
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