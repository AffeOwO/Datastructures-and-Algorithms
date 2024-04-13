#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.second<p2.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<pair<ll, ll>> vals(n);
    for(auto &x: vals) cin >> x.first;
    for(auto &x: vals) cin >> x.second;
    ll addi = 0;
    map<ll, pair<ll, vector<ll>>> col; //.first = rem; .second = pref
    for(int i=0; i<n; i++) {
        if(!col.count(vals[i].second)) col[vals[i].second].second.push_back(0);
        col[vals[i].second].second.push_back(vals[i].first+col[vals[i].second].second.back());
    } 
    int q; cin >> q;
    while(q--) {
        ll t, c, xy; cin >> t >> c >> xy;
        if(t==1) {
            addi += xy;
            col[c].first += xy;
        }
        else {
            ll l = 0, r = col[c].second.size()-1, s = 0;
            while(l<=r) {
                ll m = (l+r)/2;
                if(m*(addi-col[c].first)+col[c].second[m]<=xy) {
                    s = m;
                    l = m+1;
                }
                else r = m-1;
            }
            cout << s << endl;
        }
    }
    
}

/*
map<ll, pair<ll, pair<ll, ll>>> clr; // .first = not added to clr; .second = interval
    sort(all(vals), cmp);

    // for(auto &x: vals) cout << x.first << " " << x.second << endl;

    for(int i=0; i<n; i++) {
        if(i==0 or vals[i-1].second != vals[i].second) clr[vals[i].second].second.first = i;
        clr[vals[i].second].second.second = i;
    }
    // color i has clr[i].second.second - clr[i].second.first + 1 elements
    // for(auto &x: clr) cout << x.first << " " << x.second.second.first << " " << x.second.second.second << endl;

    vector<ll> pref(n); // sum of clr i upto jth element of vals = pref[j]
    for(int i=0; i<n; i++) {
        pref[i] = vals[i].first;
        if(i!=0 and vals[i-1].second==vals[i].second) pref[i] += pref[i-1];
    }
    // for(auto &x: pref) cout << x << " ";

    int q; cin >> q;
    while(q--) {
        ll t, col, xy; cin >> t >> col >> xy;
        if(t==1) {
            addi += xy;
            clr[col].first -= xy;
        }
        else {
            ll l = clr[col].second.first, r = clr[col].second.second, s = clr[col].second.first-1;
            while(l<=r) {
                ll m = (l+r)/2;
                if(pref[m]+(m-clr[col].second.first+1)*(addi+clr[col].first)<=xy) {
                    s = m;
                    l = m+1;
                }
                else r = m-1;
            }
            // cout << s << " " << l << " " << r << endl;
            cout << s-clr[col].second.first+1 << endl;
        }
    }
*/