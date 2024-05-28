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
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    vector<int> ind1(n), ind2(n);
    for(int i=0; i<n; i++) ind1[a[i]-1] = i;
    for(int i=0; i<n; i++) ind2[i] = ind1[b[i]-1];
    
    vector<int> dp(n, 1e9);
    dp[0] = ind2[0];
    for(int i=1; i<n; i++) {
        int l = 0, r = n-1, m;
        while(l<=r) {
            m = (l+r)/2;
            if(dp[m]>=ind2[i]) r = m-1;
            else l = m+1;
        }
        dp[r+1] = ind2[i];
    }
    for(int i=n-1; i>=0; i--) {
        if(dp[i]!=1e9) {
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