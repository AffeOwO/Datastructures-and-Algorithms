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
    vector<pair<int, int>> gcds(n); // .first = pref, .second = suf 
    // make pre and suf array for gcds and then get biggest
    vector<pair<int, int>> idk(n); // index is the element left out; .first = pref, .second = suf
    int cur = nums[0];
    for(int i=0; i<n-1; i++) {
        cur = gcd(cur, nums[i]);
        idk[i+1].first = cur;
    }
    cur = nums[n-1];
    for(int i=n-1; i>0; i--) {
        cur = gcd(cur, nums[i]);
        idk[i-1].second = cur;
    }
    int sol = idk[0].second;
    if(idk[n-1].first > sol) sol = idk[n-1].first;
    for(int i=1; i<n-1; i++) {
        int temp = gcd(idk[i].first, idk[i].second);
        if(temp > sol) sol = temp;
    }
    cout << sol << endl;
}