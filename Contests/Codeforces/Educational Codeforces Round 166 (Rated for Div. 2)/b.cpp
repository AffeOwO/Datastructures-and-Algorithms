#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), b(n+1);
    for(auto &x: a) cin >>x;
    for(auto &x: b) cin >> x;
    ll sol = 0, mini = 2e9;
    bool tmp = false;
    for(int i=0; i<n; i++) {
        sol += abs(a[i]-b[i]);
        mini = min({mini, abs(a[i]-b.back()), abs(b[i]-b.back())});
        if((a[i]<=b.back() and b[i]>=b.back()) or (a[i]>=b.back() and b.back()>=b[i])) tmp = true;
    }
    sol++;
    if(!tmp) sol += mini;

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