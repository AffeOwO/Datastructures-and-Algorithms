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
    ll n, q; cin >> n >> q;
    ll arr[n];
    ll cur = 0;
    for(ll i=0; i<n; i++) {
        ll temp; cin >> temp;
        cur = (cur+temp)%2;
        arr[i] = cur;
    }
    for(ll i=0; i<q; i++) {
        ll l, r, k; cin >> l >> r >> k;
        ll temp = 0;
        k%=2;
        if(r!=n)temp += (arr[n-1] - arr[r-1]);
        if(l!= 1) temp += arr[l-2];
        temp += ((r-l+1)*k);
        if(temp % 2 == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
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