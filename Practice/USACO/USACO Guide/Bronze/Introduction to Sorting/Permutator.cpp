#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<ll> app_a(n);
    for(int i=0; i<n; i++) app_a[i] = (i+1)*(n-i)*a[i];
    sort(all(app_a)); sort(all(b), greater<int>());
    ll sol = 0;
    for(int i=0; i<n; i++) sol += app_a[i]*b[i];

    cout << sol << endl;
}