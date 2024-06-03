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
    string s; cin >> s;
    map<char, int> cnt;
    cnt['A'] = 0; cnt['B'] = 0; cnt['C'] = 0; cnt['D'] = 0; cnt['E'] = 0; cnt['F'] = 0; cnt['G'] = 0;
    for(auto &x: s) cnt[x]++;
    ll sol = 0;
    for(auto &x: cnt) sol += max(0, m-x.second);
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