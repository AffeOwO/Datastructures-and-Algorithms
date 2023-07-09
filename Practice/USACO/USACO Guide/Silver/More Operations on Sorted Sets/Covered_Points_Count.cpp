#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    map<ll, ll> sweepy;
    for(int i=0; i<n; i++) {
        ll l, r; cin >> l >> r;
        sweepy[l]++;
        sweepy[r+1]--;
    }
    vector<ll> sol(n);
    ll cnt = 0, prev = 0;

    for(auto &x: sweepy) {
        if(cnt != 0) {
            sol[cnt-1] += (x.first-prev);
        }
        cnt += x.second;
        prev = x.first;
    }

    for(auto &x: sol) cout << x << " ";
    cout << endl;
}