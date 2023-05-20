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
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    set<int> used;
    pair<int, int> parity; // .first = even; .second = odd
    int mini = 1000000001;
    for(auto &x: nums) {
        if(used.count(x)) continue;
        if(x%2==0) parity.first++;
        else parity.second++;
        used.insert(x);
        if(x<mini) mini = x;
    }
    if(parity.first == 0 or parity.second == 0) {
        cout << "YES" << endl;
        return;
    }
    if(mini%2==1) cout << "YES" << endl;
    else cout << "NO" << endl; 
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}