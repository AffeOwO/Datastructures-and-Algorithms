#include <bits/stdc++.h>

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
    
    int n, m, q; cin >> n >> m >> q;
    // multiset S of m "01"-strings of length n
    vector<int> w(n); // val of i-th char
    for(auto &x: w) cin >> x;

    vector<int> wu(1<<n);
    for(int i=0; i<(1<<n); i++) {
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) wu[i] += w[j];
        }
    }

    vector<int> cnt(1<<n);
    for(int i=0; i<m; i++) {
        string s; cin >> s;
        int val = 0;
        for(int j=0; j<n; j++) {
            if(s[j] == '1') val += (1<<j);
        }
        cnt[val]++;
    }

    vector<vector<int>> pref(1<<n, vector<int>(101));
    for(int i=0; i<(1<<n); i++) {
        for(int j=0; j<(1<<n); j++) {
            int diff = i^j, wuval = wu[(1<<n)-1]-wu[diff];
            if(wuval<=100) pref[i][wuval] += cnt[j];
        }
        for(int j=1; j<=100; j++) pref[i][j] += pref[i][j-1];
    }

    while(q--) {
        string t; cin >> t;
        int k; cin >> k;
        // how many strings s in S such that WU(s, t) <= k
        int sol = 0;

        for(int i=0; i<n; i++) {
            if(t[i] == '1') sol += (1<<i);
        }

        cout << pref[sol][k] << endl;
    }
}