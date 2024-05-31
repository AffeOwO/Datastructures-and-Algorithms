#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll mod_exp(ll a, ll b) {
    //cout << a <<  " ";
    if(b==0) return 1;
    if(b==1) return a;
    ll cur = mod_exp(a, b/2);
    if(b%2==0) return (cur*cur)%MOD;
    else return (((cur*cur)%MOD)*a)%MOD;
}

void solve() {
    int n; cin >> n;

    vector<ll> precomp(1e6+1, 1);
    for(ll i=1; i<=(ll)1e6; i++) {
        precomp[i] = (precomp[i-1]*i)%MOD;
    }

    while(n--) {
        int a, b; cin >> a >> b;
        // calculate aCb
        cout << (precomp[a]*mod_exp((precomp[b]*precomp[a-b])%MOD, MOD-2))%MOD << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}