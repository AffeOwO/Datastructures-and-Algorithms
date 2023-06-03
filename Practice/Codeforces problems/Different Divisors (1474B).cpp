#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool is_prime(ll x) {
    for(ll i=2; i<=sqrt(x); i++) {
        if(x%i==0) return false;
    }
    return true;
}

void solve() {
    ll d; cin >> d;
    // find 2 primes >d
    for(ll i=d+1; i<d+100; i++) {
        if(is_prime(i)) {
            for(ll j=i+d; j<2*d+100; j++) {
                if(is_prime(j)) {
                    ll sol = i*j;
                    cout << sol << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}