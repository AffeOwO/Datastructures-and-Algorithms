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
    
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    while(k--) {
        int q; cin >> q;
        if(q<nums[0]) cout << 0 << endl;
        else if(q>=nums[n-1]) cout << n << endl;
        else {
            int left = 0, right = n-1; 
            while(left<=right) {
                int mid = (left+right)/2;
                //cout << left << " " << mid << " " << right << endl;
                if(nums[mid]>q and nums[mid-1]<=q) {
                    cout << mid << endl;
                    break;
                }
                else if(nums[mid]<=q) left = mid+1;
                else right = mid-1;
            }
        }
    }
}