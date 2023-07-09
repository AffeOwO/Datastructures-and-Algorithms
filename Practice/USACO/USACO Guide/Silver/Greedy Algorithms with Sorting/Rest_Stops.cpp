#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll l, n, r_f, r_b; fin >> l >> n >> r_f >> r_b; // rate is in seconds per meter (time it takes to travel 1 meter); r_f = farmer; r_b = bessie
    // r_b < r_f
    // stop i is at pos x with tastiness c
    vector<pair<ll, ll>> stops(n); // .first = pos; .second = tastiness
    for(auto &x: stops) fin >> x.first >> x.second;
    // suffix array with max tastiness from end of road+

    /*
    (implement later)
    sol:
    - stay at a stop for as long as possible if the stop has a higher tastiness than all following stops
    - do this for every stop which has this property
    */

    vector<pair<ll, ll>> suffix = {stops[n-1]};
    for(int i=n-2; i>=0; i--) {
        if(stops[i].second>suffix.back().second) suffix.push_back(stops[i]);
    }
    ll sol = 0;
    // greedy
    suffix.push_back({0, 0});
    for(int i=suffix.size()-2; i>=0; i--) {
        sol += ((suffix[i].first-suffix[i+1].first)*suffix[i].second*(r_f-r_b));
    }

    fout << sol << endl;
}