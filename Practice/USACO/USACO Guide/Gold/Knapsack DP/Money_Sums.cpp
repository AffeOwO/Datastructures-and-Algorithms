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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> vals(n);
    for(auto &x: vals) cin >> x;
    vector<bool> dp(1e5+1);
    dp[0] = true;

    for(int i=0; i<n; i++) {
        for(int j=1e5; j>=0; j--) {
            if(j-vals[i]>=0) dp[j] = (dp[j] or dp[j-vals[i]]);
        }
    }

    vector<int> sol; int cnt = 0;
    for(int i=1; i<=1e5; i++) {
        if(dp[i]) {
            cnt++;
            sol.push_back(i);
        }
    }
    cout << cnt << endl;
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}