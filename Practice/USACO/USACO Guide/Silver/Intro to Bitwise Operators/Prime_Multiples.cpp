#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> primes(k);
    for(auto &x: primes) cin >> x;
    sort(all(primes));

    ll sol = 0;
    for(ll i = 1; i<(1<<k); i++) {
        ll prod = 1;
        for(ll j = 0; j<k; j++) {
            if(i&(1<<j)) {
                if(prod>n/primes[j]) {
                    prod = n+1;
                    break;
                }
                prod *= primes[j];
            }
        }
        if(__builtin_popcount(i)%2) {
            sol += n/prod;
        }
        else sol -= n/prod;
    }
    cout << sol << endl;
}