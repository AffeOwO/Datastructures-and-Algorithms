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
    ll n, h; cin >> n >> h;  // attacks, health
    ll nums[n];
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums, nums+n);
    for(int i=0; i<n-1; i++) {
        nums[i] = nums[i+1]-nums[i];
    }
    nums[n-1] = -1;
    ll sol = 0;
    // binary search :skull: i forgot how to implement it
    ll l = 1, r = pow(10, 18)+1;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll cur = mid;
        for(int i=0; i<n-1; i++) {
            cur += min(nums[i], mid);
        }

        if(cur>=h) {
            sol = mid;
            r = mid-1;
        }
        else if(cur < h) {
            l = mid+1;
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