#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n; cin >> n;

    ll cnt = floor(sqrt(n)) + floor(cbrt(n));
    ll idk = 1;
    while(true) {
        ll temp = idk*idk*idk;
        if(temp>n) break;
        if(pow(floor(sqrt(temp)), 2) == temp) cnt--;
        idk++;
    }
    cout << cnt << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}