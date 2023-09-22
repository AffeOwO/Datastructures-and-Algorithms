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
    vector<ll> tuition(n);
    for(auto &x: tuition) cin >> x;
    sort(all(tuition));

    ll sol = 0, price = tuition[n-1];
    for(ll i=n-1; i>=0; i--) {
        if((n-i)*tuition[i]>=sol) {
            sol = (n-i)*tuition[i];
            price = tuition[i];
        }
    }

    cout << sol << " " << price << endl;
}