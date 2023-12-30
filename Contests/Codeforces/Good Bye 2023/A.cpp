#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, k; cin >> n >> k;
    ll prod = 1;
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        prod *= cur;
    }
    if(2023%prod!=0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << 2023/prod << " ";
        for(int i=0; i<k-1; i++) cout << 1 << " ";
        cout << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}