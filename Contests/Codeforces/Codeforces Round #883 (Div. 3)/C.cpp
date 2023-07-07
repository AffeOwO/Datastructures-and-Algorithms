#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool comp(pair<pair<ll, ll>, ll> p1, pair<pair<ll, ll>, ll> p2) {
    if(p1.first.first==p2.first.first) return p1.first.second<p2.first.second;
    return p1.first.first>p2.first.first;
}

void solve() {
    ll n, m, h; cin >> n >> m >> h;
    // each task = 1 point, penalty = minutes after start
    // rudoloph is #1
    // n participants; m problems; h minutes
    // t[i][j] predicts how long participant i needs for problem j
    // solve optimally
    vector<vector<ll>> ti(n, vector<ll>(m));
    for(auto &x: ti) {
        for(auto &y: x) cin >> y;
        sort(all(x));
    }
    vector<pair<pair<ll, ll>, ll>> res(n); // first.first = solved; first.second = penalty; .second = original index
    for(int i=0; i<n; i++) {
        ll cnt = 0, pen = 0, temp = 0;
        for(int j=0; j<m; j++) {
            temp += ti[i][j];
            if(temp<=h) {
                cnt++;
                pen += temp;
            }
            else break;
        }
        res[i] = {{cnt, pen}, i};
    }
    sort(all(res), comp);    
    for(int i=0; i<n; i++) {
        if(res[i].second == 0) cout << i+1 << endl;
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