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
    vector<ll> sol;
    for(int i=1; i<n; i++) {
        if(gcd(i, n) == 1) sol.push_back(i);
    }
    while(true) {
        ll cur = 1;
        
        for(auto &x: sol) cur = (cur*x)%n;
        
        if(cur == 1) break;
        vector<ll> new_sol;
        for(auto &x: sol) {
            if(x==cur) continue;
            new_sol.push_back(x);
        }
        sol = new_sol;
    }

    cout << sol.size() << endl;
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}