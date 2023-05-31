#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll exp(ll x, ll n, ll m) {
    assert(n>=0);
    x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			res = res * x % m;
		}
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    ll a, b, c;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c;
        ll pow_bc = exp(b, c, MOD - 1);
		ll ans = exp(a, pow_bc, MOD);

		cout << ans << '\n'; 
    }
}