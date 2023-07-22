#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int a, b, c; cin >> a >> b >> c; // three monsters with health a, b, c
    // every shot deals 1 damage to one monster and every 7n shot deals 1 damage to all monsters
    if((a+b+c)%9==0 and min({a,b,c})>=(a+b+c)/9) cout << "YES" << endl;
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