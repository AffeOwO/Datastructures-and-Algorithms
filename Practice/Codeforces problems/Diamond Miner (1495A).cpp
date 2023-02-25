#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

void solve() {
    int n; cin >> n;
    ll miners[n];
    ll mines[n];
    int m1 = 0, m2 = 0;
    for(int i=0; i<n*2; i++) {
        ll x, y;
        cin >> x >> y;
        if(x==0) {
            miners[m1++] = y*y;
        }
        else {
            mines[m2++] = x*x;
        }
    }
    sort(miners, miners+n);
    sort(mines, mines+n);

    ld sol = 0;
    for(int i=0; i<n; i++) {
        ld cur_miner = miners[i], cur_mine = mines[i];
        ld dist = sqrt(cur_miner+cur_mine);
        sol += dist;
    }
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout.precision(10);

    int t; cin >> t;
    while(t--) {
        solve();
    }
}