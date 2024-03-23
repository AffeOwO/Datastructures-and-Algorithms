#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    ll sol = 0, temp = 0, maxi = 0;

    for(ll i=0; i<min(n, k); i++) {
        maxi = max(maxi, b[i]);
        temp += a[i];
        sol = max(sol, temp+maxi*(k-i-1));
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