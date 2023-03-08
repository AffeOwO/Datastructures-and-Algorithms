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

void solve() {
    int n; cin >> n;
    int nums[n];
    bool ones = true;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        if(nums[i] != 1 && i!=0 && i!=n-1) ones = false;
    }
    if(ones) {
        cout << -1 << endl;
        return;
    }
    // j is never index 0 or n-1
    if(n==3) {
        if(nums[1]%2==1) {
            cout << -1 << endl;
            return;
        }
        cout << nums[1] / 2 << endl;
        return;
    }

    ll sol = 0;
    for(int i=1; i<n-1; i++) {
        sol += nums[i]/2 + nums[i]%2;
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