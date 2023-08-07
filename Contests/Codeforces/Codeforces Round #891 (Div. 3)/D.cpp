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
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<pair<int, int>> dif(n);
    for(int i=0; i<n; i++) dif[i] = make_pair(a[i] - b[i], i);
    // node u connects to v (u != v) if dif[u] >= dif[v]
    sort(all(dif));
    vector<int> sol;
    for(int i=n-1; i>=0; i--) {
        if(dif[i].first == dif[n-1].first) sol.push_back(dif[i].second+1);
    }

    sort(all(sol));
    cout << sol.size() << endl;
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}