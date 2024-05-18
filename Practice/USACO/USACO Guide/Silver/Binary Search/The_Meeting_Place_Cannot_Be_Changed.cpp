#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> x(n), v(n);
    for(auto &y: x) cin >> y;
    for(auto &y: v) cin >> y;

    ld l = 0, r = 1e9, m;
    for(int i=0; i<100; i++) {
        m = (l+r)/2;
        pair<ld, ld> cur = {0, 1e9};
        for(int j=0; j<n; j++) {
            ld le = x[j]-m*v[j], ri = x[j]+m*v[j];
            if(le>cur.first) cur.first = le;
            if(ri<cur.second) cur.second = ri;
        }
        if(cur.first<=cur.second) r = m;
        else l = m;
    
    }
    cout << setprecision(14) << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}