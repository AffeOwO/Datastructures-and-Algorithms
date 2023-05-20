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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<int> ca = a, cb = b;
    sort(all(ca)); sort(all(cb));
    map<int, vector<int>> idk;
    for(int i=0; i<n; i++) {
        idk[ca[i]].push_back(cb[i]);
    }
    for(auto &x: a) {
        cout << idk[x][idk[x].size()-1] << " ";
        idk[x].pop_back();
    }
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