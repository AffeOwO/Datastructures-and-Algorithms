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

void solve() {
    int n; cin >> n;
    int nums[n];
    unordered_set<int> steps;
    bool ret = false;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        steps.insert(nums[i]);
        if(nums[i] < i+1) {
            ret = true;
        }
    }
    if(ret) {
        cout << -1 << endl;
        return;
    }
    int sol[n];

    int cur = 0;
    for(int i=0; i<n; i++) {
        if(i==0 || (i != 0 && nums[i-1] != nums[i])) {
            sol[i] = nums[i];
        }
        else {
            cur++;
            while(steps.count(cur)) cur++;
            sol[i] = cur;
        }
    }

    for(int i=0; i<n; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;    
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}