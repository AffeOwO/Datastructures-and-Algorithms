#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first+p1.second<p2.first+p2.second;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> coords(n);
    for(auto &x: coords) cin >> x.first >> x.second;
    // points i is connected to j iff |x_i - x_j| >= w_i + w_j
    sort(all(coords), comp);
    int sol = 1, cur = coords[0].first+coords[0].second;
    for(int i=1; i<n; i++) {
        if(coords[i].first-coords[i].second>=cur) {
            cur = coords[i].first+coords[i].second;
            sol++;
        }
    }
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}