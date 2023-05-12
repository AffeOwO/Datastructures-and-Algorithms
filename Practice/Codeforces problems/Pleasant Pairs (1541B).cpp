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

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n+1);
    for(int i=1; i<=n; i++) cin >> arr[i];
    // 1-indexed

    ll sol = 0;

    for(ll i=1; i<n; i++) {
        for(ll j=i-(i%arr[i])+(arr[i]-i%arr[i]); j<=n; j+=arr[i]) {
            if(j<=i) continue;
            if(i+j == arr[i] * arr[j]) sol++;
        }
    }

    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}