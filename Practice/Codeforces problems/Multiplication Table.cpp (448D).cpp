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
    ll n, m, k; cin >> n >> m >> k;

    ll l = 1, r = n*m, sol = n*m;
    while(l<=r) {
        ll mid = (l+r)/2;
        ll cur = 0;

        for(int i=1; i<=n; i++) {
            cur += (min(mid/i, m));
        }
        //cout << mid << " " << cur << endl;
        if(cur>=k) {
            sol = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}