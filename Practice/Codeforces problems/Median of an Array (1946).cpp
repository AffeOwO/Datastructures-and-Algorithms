#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    sort(all(arr));
    int idk = arr[(n+1)/2-1], sol = 1;
    for(int i=(n+1)/2; i<n; i++) {
        sol += (arr[i]==idk);
    }

    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}