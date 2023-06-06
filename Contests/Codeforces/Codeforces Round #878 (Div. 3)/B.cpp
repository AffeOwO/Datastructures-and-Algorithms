#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n, k; cin >> n >> k; // n = money, 0...k-1 desert, ith desert = 2^i
    ll sol = 0;
    // all binary numbers<=n ceil(lg())
    ll idk = pow(2, k)-1;
    if(k<=32 and idk<=n) cout << idk+1 << endl;
    else cout << n+1 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}