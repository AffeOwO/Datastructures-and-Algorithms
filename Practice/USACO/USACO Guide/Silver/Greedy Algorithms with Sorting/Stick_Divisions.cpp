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
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, n; cin >> x >> n;
    multiset<int> sticks;
    for(int i=0; i<n; i++) {
        int t; cin >> t;
        sticks.insert(t);
    }
    ll sol = 0;
    while(sticks.size() != 1) {
        int cur = *sticks.begin() + *++sticks.begin();
        sol += cur;
        sticks.insert(cur);
        sticks.erase(sticks.begin()); sticks.erase(sticks.begin());
        /*
        cout << cur << "---";
        for(auto &x: sticks) cout << x << " ";
        cout << endl;
        */
    } 
    cout << sol << endl;
}