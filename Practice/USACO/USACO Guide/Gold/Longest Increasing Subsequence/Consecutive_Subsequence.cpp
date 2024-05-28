#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    map<int, int> dp;
    for(int i=0; i<n; i++) {
        if(!dp.count(a[i]-1)) dp[a[i]] = 1;
        else if(!dp.count(a[i])) dp[a[i]] = dp[a[i]-1]+1;
        else dp[a[i]] = max(dp[a[i]-1]+1, dp[a[i]]);
    }
    pair<int, int> sol;
    for(auto &x: dp) {
        if(x.second>sol.first) sol = {x.second, x.first};
    }
    cout << sol.first << endl;
    int cur = sol.second-sol.first+1;
    for(int i=0; i<n; i++) {
        if(a[i]==cur) {
            cout << i+1 << " ";
            cur++;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}