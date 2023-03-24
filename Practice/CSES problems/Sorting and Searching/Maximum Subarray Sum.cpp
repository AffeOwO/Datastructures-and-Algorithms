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
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    ll sol = nums[0], cur = 0;
    for(auto &x: nums) {
        cur += x;
        if(cur>sol) sol = cur;
        if(cur<0) cur = 0;
    }
    cout << sol << endl;
}