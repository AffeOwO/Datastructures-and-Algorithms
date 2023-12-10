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

    int n, s, k; cin >> n >> s >> k;
    vector<pair<ll, ll>> products(n);
    for(auto &x: products) cin >> x.first >> x.second;
    ll price = 0;
    for(auto &x: products) price += (x.first*x.second);
    if(price>=s) cout << price << endl;
    else cout << price+k << endl;
}