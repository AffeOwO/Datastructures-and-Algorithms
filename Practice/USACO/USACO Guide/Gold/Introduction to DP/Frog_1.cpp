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
    vector<int> stones(n);
    for(auto &x: stones) cin >> x;
    vector<int> dp(n);
    dp[1] = abs(stones[1]-stones[0]);
    for(int i=2; i<n; i++) {
        dp[i] = min(dp[i-1]+abs(stones[i]-stones[i-1]), dp[i-2]+abs(stones[i]-stones[i-2]));
    }
    //for(auto &x: dp) cout << x << " ";
    //cout << endl;
    cout << dp[n-1] << endl;
}