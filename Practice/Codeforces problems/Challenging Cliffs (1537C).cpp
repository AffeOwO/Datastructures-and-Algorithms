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
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    sort(all(nums));
    
    if(n==2) {
        cout << nums[0] << " " << nums[1] << endl;
        return;
    }

    int dif = nums[n-1]+1, cur;
    for(int i=0; i<n-1; i++) {
        if(nums[i+1]-nums[i] < dif) {
            cur = i;
            dif = nums[i+1] - nums[i];
        }
        else if(nums[i+1]-nums[i] == dif and i==n-2) cur = i;
    }
    cout << nums[cur] << " ";
    for(int i=(cur+2)%n; i != cur; i = (i+1)%n) cout << nums[i] << " "; 
    cout << nums[cur+1] << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}