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
    vector<int> p(n);
    for(auto &x: p) cin >> x;

    for(int i=1; i<=n; i++) {
        if(i==p[p[i-1]-1]) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}