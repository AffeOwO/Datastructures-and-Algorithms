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

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    
    ll sol = 0;
    // if you buy m items, then bob will take the k ones for free with the highest b[i]
    vector<pair<ll, ll>> idk(n);
    for(int i=0; i<n; i++) {
        if(b[i]-a[i]<=0) continue;
        sol += (b[i]-a[i]); 
        idk.push_back({b[i], i});
    }
    sort(all(idk));
    if(idk.size()<=k) {
        cout << 0 << endl;
        return;
    }
    if(k==0) {
        cout << sol << endl;
        return;
    }
    //cout << sol << endl;
    //vector<bool> freeg(n);
    multiset<ll> as;
    vector<pair<ll, ll>> bs;
    for(int i=idk.size()-k; i<idk.size(); i++) {
        //freeg[idk[i].second] = true;
        as.insert(a[idk[i].second]);
        sol -= idk[i].first;
    }
    //cout << sol << endl;
    for(int i=0; i<idk.size()-k; i++) bs.push_back({idk[i].first, idk[i].second});
    sort(all(bs));
    auto pnt = *as.rbegin();
    for(int i=bs.size()-1; i>=0; i--) {
        if(pnt<=bs[i].first or as.size()==0) break;
        sol += pnt;
        as.erase(as.find(pnt));
        sol -= bs[i].first;
        as.insert(a[bs[i].second]);
        pnt = *as.rbegin();
        //cout << sol << endl;
    }
    
    // maximize sol by +a[i] -b[j] if freeg[i] and not freeg[j] and both are in idk
    

    cout << max((ll) 0, sol) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}