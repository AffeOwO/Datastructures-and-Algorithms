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
    int n; cin >> n;
    vector<int> nums(n+1);
    int cur=0;
    for(int i=1; i<=n; i++) {
        int temp; cin >> temp;
        cur += temp;
        nums[i] = cur;
    }
    // kinda binary search
    int left = 1, right = n;
    while(left <= right) {
        int mid = (left+right)/2+1;
        cout << "? " << mid-left;
        for(int i=left; i< mid; i++) cout << " " << i;
        cout << endl;
        cout.flush();
        int weights; cin >> weights;
        if(weights != nums[mid-1] - nums[left-1]) {
            right = (left+right)/2;
        }
        else left = mid;
        if(mid-left==1 && weights != nums[mid]) break;
    }
    cout << "! " << left << endl;
    cout.flush();
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
    exit;
}