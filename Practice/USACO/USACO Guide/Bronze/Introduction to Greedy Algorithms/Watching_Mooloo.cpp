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

    ll n, k; cin >> n >> k;
    vector<ll> days(n);
    for(auto &x: days) cin >> x;
    ll sol = k+1;
    for(int i=1; i<n; i++) {
        sol += min((ll)k+1, days[i]-days[i-1]);
    }

    cout << sol << endl;
}