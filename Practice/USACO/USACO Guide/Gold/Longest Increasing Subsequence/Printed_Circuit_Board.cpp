#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(auto &x: a) cin >> x.first >> x.second;
    sort(all(a));
    int sol = 0, cnt = 0;
    vector<int> dp(n, -1e9);

    dp[0] = a[0].second;

    for(int i=1; i<n; i++) {
        int l = 0, r = n-1, m;
        while(l<=r) {
            m = (l+r)/2;
            if(dp[m]<=a[i].second) r = m-1;
            else l = m+1;
        }
        dp[r+1] = a[i].second;
    }

    for(int i=n-1; i>=0; i--) {
        if(dp[i]>=0) {
            cout << i+1 << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}