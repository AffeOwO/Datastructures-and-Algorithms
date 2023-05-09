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

map<int, int> cache;

void solve() {
    ll n; cin >> n;
    while(true) {
        if(cache.count(n) and cache[n] != 1) {
            cout << n << endl;
            return;
        }
        ll digits = 0, idk = n;
        while(idk>0) {
            digits += (idk%10);
            idk /= 10;
        }
        ll temp = gcd(digits, n);
        cache[n] = temp;
        if(temp!=1) {
            cout << n << endl;
            return;
        }
        n++;
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