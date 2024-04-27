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
    int n, k; cin >> n >> k;
    map<int, int> cnt;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        cnt[temp]++;
    }
    vector<int> idk;
    for(auto &x: cnt) idk.push_back(x.second);
    sort(all(idk), greater<int>());

    while(idk[0]>=k) {
        idk[0] -= k;
        sort(all(idk), greater<int>());
        idk[0] += (k-1);
    }
    int sol = 0;
    for(auto &x: idk) sol += x;
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}