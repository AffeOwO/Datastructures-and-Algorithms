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
    // height of nail and length of rope
    vector<pair<int, int>> idk(n);
    for(auto &x: idk) cin >> x.first >> x.second;
    int sol = 0;
    for(auto &x: idk) {
        if(x.first>x.second) sol++;
    }
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}