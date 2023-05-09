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

bool cstom(int a, int b) {
    return (a%2)<(b%2);
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    // later
    sort(all(nums), cstom); // even then odd
    int sol = 0;

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            sol += (gcd(nums[i], 2*nums[j])!=1);
        }
    }

    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}