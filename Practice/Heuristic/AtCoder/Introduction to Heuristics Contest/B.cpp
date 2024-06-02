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

int d; 
vector<int> c(26), state(d, 0), sol(d, 0);
vector<vector<int>> mat;

int calc(vector<int> s) {
    vector<int> last(26, -1);
    int ret = 0;
    for(int i=0; i<d; i++) {
        last[s[i]] = i;
        ret += mat[i][s[i]];
        for(int j=0; j<26; j++) ret -= c[j]*(i-last[j]);
        cout << ret << endl;
    }
    return ret;
}

void solve() {
    cin >> d;
    for(auto &x: c) cin >> x;
    mat.resize(d, vector<int>(26));
    for(auto &x: mat) {
        for(auto &y: x) cin >> y;
    }
    vector<int> tmp(d);
    for(auto &x: tmp) {
        cin >> x;
        x--;
    }
    calc(tmp);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}