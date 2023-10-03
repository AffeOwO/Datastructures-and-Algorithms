#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, k; cin >> n >> k;
    // n planks; k colors
    // repaint 1 blank max
    map<int, vector<int>> bridge;
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        if(!bridge.count(x)) bridge[x].push_back(0);
        bridge[x].push_back(i);
    }
    int sol = n;

    for(auto &x: bridge) {
        vector<int> difs;
        x.second.push_back(n+1);
        for(int i=1; i<x.second.size(); i++) {
            difs.push_back(x.second[i]-x.second[i-1]);
        }
        sort(all(difs));
        int temp = (difs.back()+1)/2;
        difs.pop_back();
        sol = min(sol, max(temp-1, difs.back()-1));
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