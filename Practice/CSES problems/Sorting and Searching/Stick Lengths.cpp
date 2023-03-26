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
    
    int n; cin >> n;
    map<int, int> nums;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        nums[temp]++;
    }
    ll cur = 0, sol = 0;
    bool idk = false;
    for(auto &x: nums) {
        if(cur<=n/2 and cur+x.second>n/2) {
            idk = true;
            for(auto &y: nums) {
                sol += (y.second*(abs(x.first-y.first)));
            }
        }
        cur += x.second;
        if(idk) {
            ll temp = 0;
            for(auto &y: nums) {
                temp += (y.second*(abs(x.first-y.first)));
            }
            if(temp<sol) sol = temp;
            break;
        }
    }
    if(sol == 0 and nums.size() > 1) {
        for(auto &x: nums) {
            sol += (x.second*x.first);
        }
    }
    cout << sol << endl;
}