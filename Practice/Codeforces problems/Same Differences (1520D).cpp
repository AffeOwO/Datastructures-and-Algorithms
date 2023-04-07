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
    map<ll, ll> sol;
    ll cnt = 0;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        temp -= i;
        sol[temp]++;
    }
    for(auto &x: sol) {
        cnt += ((x.second*(x.second-1))/2);
    }
    cout << cnt << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve(); 
}