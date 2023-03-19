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
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    sort(nums.begin(), nums.end());
    vector<ll> idk(n);
    idk[0] = 1;
    ll cur = 0;
    for(int i=0; i<n-1; i++) {
        cur += nums[i];
        idk[i+1] = cur;
    }
    for(int i=0; i<n; i++) {
        if(nums[i] > idk[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}