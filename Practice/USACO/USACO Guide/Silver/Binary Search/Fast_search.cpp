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
    sort(all(nums));
    int k; cin >> k;
    while(k--) {
        int l, r; cin >> l >> r;
        int pnt1, pnt2;
        
        int left = -1, right = n;
        while(left+1<right) {
            int mid = (left+right)/2;
            // find mid such that nums[mid]>=l and nums[mid-1]<l
            if(nums[mid]<l) left=mid;
            else right=mid;
        }
        pnt1 = right;
        
        left = -1, right = n;
        while(left+1<right) {
            int mid = (left+right)/2;
            if(nums[mid]>r) right=mid;
            else left=mid;
        }
        pnt2 = right;
        cout << pnt2-pnt1 << " ";
    }
    cout << endl;
}