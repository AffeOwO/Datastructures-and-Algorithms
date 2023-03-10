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

bool parity(int number) {
    return number > 0;
}

void solve() {
    int n; cin >> n;
    vector<ll> nums;
    for(int i=0; i<n; i++) {
        ll temp; cin >> temp;
        nums.push_back(temp);
    }
    ll sol = 0, cur = -1000000069;
    bool par = parity(nums[0]);

    for(int i=0; i<n; i++) {
        bool cur_par = parity(nums[i]);
        if(par == cur_par && nums[i] > cur) cur = nums[i];
        else if(par != cur_par) {
            par = cur_par;
            sol += cur;
            cur = nums[i];
        }
    }
    sol += cur;

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