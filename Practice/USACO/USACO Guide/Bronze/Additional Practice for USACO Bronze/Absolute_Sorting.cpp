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
    vector<int> vec(n);
    for(auto &x: vec) cin >> x;

    // 0<=x<=1e9
    pair<int, int> sol = make_pair(0, 1e9);
    for(int i=0; i<n-1; i++) {
        if(vec[i+1]==vec[i]) continue;
        else if(vec[i+1]>vec[i]) sol.second = min(sol.second, vec[i]+(vec[i+1]-vec[i])/2);
        else sol.first = max(sol.first, vec[i+1]+(vec[i]-vec[i+1]+1)/2);
    }

    if(sol.first<=sol.second) cout << sol.first << endl;
    else cout << -1 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}