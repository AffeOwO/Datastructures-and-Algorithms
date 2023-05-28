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
    
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    int sol = 0;
    sort(all(nums));
    for(int i=0; i<n; i++) {
        if(x>=nums[i]) {
            sol++;
            x -= nums[i];
        }
        else break;
    }
    cout << sol << endl;
}