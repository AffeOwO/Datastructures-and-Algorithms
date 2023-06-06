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
    vector<int> bosses(n);
    for(auto &x: bosses) cin >> x;

    // friend begins with session
    vector<pair<int, bool>> dp(n+1); // .first = val, .second = player: true -> friend; false -> you
    dp[0] = {0, true};
    // this wont produce optimal solution everytime i think
    // maybe do it reverse
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}