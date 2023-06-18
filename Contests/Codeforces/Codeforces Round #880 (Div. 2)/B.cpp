#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n, k, g; cin >> n >> k >> g; // n austronauts will be given bonuses of (total) k gold coins
    // each gold coin is worth g silver coins -> k*g silver coins for n austronauts
    ll temp = (g+1)%2; // 0 if odd 1 if even
    ll idk = (g/2 - temp)*n, idk2=k*g;
    if(idk > idk2) {
        cout << idk2 << endl;
    }
    else {
        cout << idk - (idk)%g << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}