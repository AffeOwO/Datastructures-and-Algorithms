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

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; cin >> n >> q;
    ll nums[n];
    ll cur = 0;
    ll sum_arr[n+1];
    sum_arr[0] = 0;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        cur += nums[i];
        sum_arr[i+1] = cur;
    }
    for(int i=0; i<q; i++) {
        pair<int, int> query;
        cin >> query.first >> query.second;
        cout << sum_arr[query.second] - sum_arr[query.first-1] << endl;
    }
}