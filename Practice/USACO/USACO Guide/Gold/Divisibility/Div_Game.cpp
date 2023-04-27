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

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    // z|n, z only has only one distinct prime factor
    // just compute prime factors of z, and then to pC2


    int primes = 0, sol = 0;
    for(ll i=2; i<=sqrt(n)+1; i++) {
        while(n%i==0) {
            n /= i;
            primes++;
        }
        for(int i=1; primes-i>=0; i++) {
            primes -= i;
            sol++;
        }
        primes = 0;
    }
    if(n>1) sol++;
    cout << sol << endl;
}