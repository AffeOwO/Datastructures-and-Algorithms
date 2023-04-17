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
    ll sol = 0;

    for(ll i=0; i<n-1; i++) {
        if(nums[i+1] > nums[i]) {
            if(i+3 > n) {
                cout << -1 << endl;
                return;
            }
            ll dif = nums[i+1]-nums[i];
            nums[i+1] -= dif;
            nums[i+2] -= dif;
            if(nums[i+2] < 0) {
                cout << -1 << endl;
                return;
            }
            sol += dif*2;
            //cout << dif << " " << sol << endl;
        }
        else if(nums[i] > nums[i+1]) {
            if(i%2==0) {
                cout << -1 << endl;
                return;
            }
            ll dif = nums[i] - nums[i+1];
            sol += dif*(i+1);
            //cout << dif << " " << sol << endl;
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