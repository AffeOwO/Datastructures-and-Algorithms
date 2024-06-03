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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(auto &x: a) {
        for(auto &y: x) cin >> y;
    }
    for(auto &x: b) {
        for(auto &y: x) cin >> y;
    }

    vector<set<int>> v1, v2;

    for(int j=0; j<m; j++) {
        set<int> s1, s2;
        for(int i=0; i<n; i++) {
            s1.insert(a[i][j]);
            s2.insert(b[i][j]);
        }
        v1.push_back(s1);
        v2.push_back(s2);
    }
    sort(all(v1)); sort(all(v2));
    
    if(v1==v2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}