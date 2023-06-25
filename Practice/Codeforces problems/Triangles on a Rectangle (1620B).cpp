#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll w, h; cin >> w >> h;
    // rectangle with points [0, 0], [w, 0], [0, h], [w, h]
    vector<vector<ll>> points(4);  // [0] = x-line, [1] = h-line, [2] = y-line, [3] = w-line
    int k; cin >> k; points[0].resize(k);
    for(auto &x: points[0]) cin >> x;
    cin >> k; points[1].resize(k);
    for(auto &x: points[1]) cin >> x;
    cin >> k; points[2].resize(k);
    for(auto &x: points[2]) cin >> x;
    cin >> k; points[3].resize(k);
    for(auto &x: points[3]) cin >> x;
    // all in increasing order

    // find area of triangle, where 2 points are on one line and the other on some other
    ll sol = 0; // [ABC] = ah/2
    ll cur = (points[0][points[0].size()-1]-points[0][0])*h;
    //cout << cur << " " << sol << endl;
    sol = max(sol, cur);
    cur = (points[1][points[1].size()-1]-points[1][0])*h;
    //cout << cur << " " << sol << endl;
    sol = max(sol, cur);
    cur = (points[2][points[2].size()-1]-points[2][0])*w;
    //cout << cur << " " << sol << endl;
    sol = max(sol, cur);
    cur = (points[3][points[3].size()-1]-points[3][0])*w;
    //cout << cur << " " << sol << endl;
    sol = max(sol, cur);
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}