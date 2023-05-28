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

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for(auto &x: movies) cin >> x.first >> x.second;
    sort(all(movies), comp);
    multiset<int> idk;
    for(int i=0; i<k; i++) idk.insert(0);
    
    int sol = 0;
    // for(auto &x: movies) cout << x.first << " " << x.second << "---";
    // cout << endl;

    for(auto &x: movies) {
        if(x.first>=*idk.begin()) {
            idk.erase(--idk.upper_bound(x.first));
            idk.insert(x.second);
            sol++;
        }
        /*
        cout << x.first << " " << x.second << " " << sol << "-->";
        for(auto &y: idk) cout << y << " ";
        cout << endl;
        */
    }
    cout << sol << endl;
}