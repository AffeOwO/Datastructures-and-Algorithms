#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> ab(n);
    for(auto &x: ab) cin >> x.first;
    for(auto &x: ab) cin >> x.second;
    int m; cin >> m;
    vector<int> d(m);
    for(auto &x: d) cin >> x;
    multiset<int> ms;
    bool tmp = false;
    for(auto &x: ab) {
        if(x.first != x.second) ms.insert(x.second);
        if(d.back()==x.second) tmp = true;
    }
    if(!tmp) {
        cout << "NO" << endl;
        return;
    }
    for(int i=m-1; i>=0; i--) {
        if(ms.count(d[i])) ms.erase(ms.find(d[i]));
    }
    if(ms.size()) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}