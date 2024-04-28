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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;
    map<ll, ll> idk;
    
    for(int i=0; i<n; i++) {
        ll l, r, v; cin >> l >> r >> v; // 0 -> 1e9-1
        idk[l] += v;
        idk[r] -= v;
    }
    vector<pair<ll, ll>> compressed;
    ll cnt = 0;
    for(auto &x: idk) {
        cnt += x.second;
        compressed.push_back({cnt, x.first});
    }
    //for(auto &x: compressed) cout << x.first << " " << x.second << endl;
    vector<ll> pref(compressed.size()); // pref[i] = sum on interval [0, compressed[i].second)
    for(int i=1; i<compressed.size(); i++) {
        pref[i] = pref[i-1] + (compressed[i].second-compressed[i-1].second)*compressed[i-1].first;
    }
    //for(auto &x: pref) cout << x << " ";
    //cout << endl;

    for(int i=0; i<q; i++) {
        ll l, r, sol = 0; cin >> l >> r;
        if(l>=compressed.back().second or r<compressed[0].second) {
            cout << 0 << endl;
            continue;
        }

        ll le = 0, ri = compressed.size()-1, mi, so1 = 0, so2 = compressed.size()-1;
        while(le<=ri) {
            mi = (le + ri)/2;
            if(compressed[mi].second<=l) {
                so1 = mi;
                le = mi + 1;
            }
            else ri = mi - 1;
        }
        
        if(r>=compressed.back().second) {
            sol = pref.back()-pref[so1];
            sol -= (l-compressed[so1].second)*compressed[so1].first;
        }
        else {
            le = 0, ri = compressed.size()-1;
            while(le<=ri) {
                mi = (le + ri)/2;
                if(compressed[mi].second>=r) {
                    ri = mi - 1;
                    so2 = mi;
                }
                else le = mi + 1;
            }
            sol = pref[so2]-pref[so1];
            sol -= max((ll)0, (l-compressed[so1].second)*compressed[so1].first);
            sol -= (compressed[so2].second-r)*compressed[so2-1].first;
        }
        //cout << so1 << " " << so2 << " ";
        cout << sol << endl;
    }
}