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
    vector<pair<int, int>> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(all(nums));

    vector<int> sol(n);
    for(int i=0; i<n; i++) sol[nums[i].second] = n-i;
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}