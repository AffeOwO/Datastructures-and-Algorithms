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
#define all(x) (x).begin(), (x).end();
#define MOD 1000000007;

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<= 6 && i-j >= 0; j++) {
            (dp[i] += dp[i-j]) %= MOD;
        }
    }

    cout << dp[n] << endl;
}