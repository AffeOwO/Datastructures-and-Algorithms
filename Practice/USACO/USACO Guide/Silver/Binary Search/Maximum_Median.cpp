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
    
    ll n, k; cin >> n >> k;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    sort(all(nums));

    if(k<=nums[n/2]-nums[n/2+1]) cout << nums[n/2]+k << endl;
    else {
        ll pnt = n/2+1;
        while(true) {
            if(pnt>=n) {
                cout << nums[n-1]+k/(n/2+1) << endl;
                break;
            }
            ll temp = (pnt-n/2)*(nums[pnt]-nums[pnt-1]);
            if(temp<=k) {
                k-=temp;
                pnt++;
            }
            else {
                cout << nums[pnt-1]+k/(pnt-n/2) << endl;
                break;
            }
        }
    }
}