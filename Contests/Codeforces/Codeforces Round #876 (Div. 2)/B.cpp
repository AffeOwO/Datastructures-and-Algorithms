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
    int n; cin >> n; // on, off, broken
    // start = all off
    map<ll, vector<ll>> lamps;
    for(int i=0; i<n; i++) {
        ll a, b; cin >> a >> b;
        lamps[a].push_back(b);
    }
    ll sol = 0; // +b_i points if you turn lamp i on
    // all lamps with a_i<=x break
    // greedy wont work
    int turned_on = 0;
    int last = 0, cur = 0;
    vector<pair<ll, int>> cnt(n);
    for(auto &x: lamps) {
        sort(all(x.second));
        cnt[cur].first = x.first;
        for(int i=x.second.size()-1; i>=0; i--) {
            turned_on++;
            sol += x.second[i];
            cnt[cur].second++;
            if(turned_on>=cnt[last].first) {
                turned_on -= cnt[last].second;
                if(last==cur) {
                    last++;
                    break;
                }
                last++;
            }
        }
        cur++;
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