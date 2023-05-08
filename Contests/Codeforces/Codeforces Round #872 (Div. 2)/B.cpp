#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, m; cin >> n >> m;
    vector<int> idk(n*m);
    for(auto &x: idk) cin >> x;
    sort(all(idk));
    
    ll sol = ((n-1)*(m-1)*(idk[n*m-1]-idk[0]))+(max(n-1, m-1)*(idk[n*m-1]-idk[0]))+(min(n-1, m-1)*(idk[n*m-1]-idk[1]));
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