#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll mod_exp(ll a, ll b) {
    if(b==0) return 1;
    if(b==1) return a;
    ll cur = mod_exp(a, b/2);
    if(b%2==0) return (cur*cur)%MOD;
    else return (((cur*cur)%MOD)*a)%MOD;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<ll> fac(2e6+1, 1);
    for(ll i = 1; i<=2e6; i++) fac[i] = (fac[i-1]*i)%MOD;
    ll sol = (fac[n+m-1]*mod_exp((fac[m]*fac[n-1])%MOD, MOD-2))%MOD;
    cout << sol << endl;
}