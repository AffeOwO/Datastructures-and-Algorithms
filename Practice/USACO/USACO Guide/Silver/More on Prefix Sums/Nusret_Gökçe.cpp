#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> slices(n);
    for(auto &x: slices) cin >> x;

    for(int i=0; i<n-1; i++) slices[i+1] = max(slices[i+1], slices[i]-m);
    for(int i=n-1; i>0; i--) slices[i-1] = max(slices[i-1], slices[i]-m);

    for(auto &x: slices) cout << x << " ";
    cout << endl;
}