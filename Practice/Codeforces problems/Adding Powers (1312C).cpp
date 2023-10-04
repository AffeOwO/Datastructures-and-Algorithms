#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n, k; cin >> n >> k;
    bool pos = true;
    set<ll> nums; nums.insert(0);
    for(int i=0; i<n; i++) {
        ll x; cin >> x;
        if(x!=0 and nums.count(x)) pos = false;
        nums.insert(x); 
    }
    /*
    i-th step (0-indexed):
    - increase arr[j] (any j) by k^i
    - do nothing
    */
    // reverse this process
    // if an element in arr >= k^x for some x, then k^x was added to that element

    ll texp = 0, tval = 1;
    while(true) {
        if(tval*k>(*nums.rbegin())) break;
        tval *= k;
        texp++;
    }
    while(texp>=0) {
        if((*nums.rbegin())>=tval) {
            ll idk = (*nums.rbegin()-tval);
            if(idk != 0 and nums.count(idk)) pos = false;
            nums.insert(idk); nums.erase(--nums.end()); 
        }
        //cout << texp << " " << tval << endl;
        texp--; tval /= k;
    }
    
    if(*nums.rbegin()>0) pos = false;
    
    if(pos) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}