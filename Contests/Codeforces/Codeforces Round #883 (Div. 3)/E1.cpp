#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n; cin >> n;
    // is there a snowflake, wehre each node has k "children"

    /* (some integer k > 1)
    - graph has initially only 1 node
    - initial node is connected to k new nodes
    - each vertex that is only connected to one node gets connected to k new nodes (at least once)
    */
    // works for k iff n >= k(k+1) + 1 and when n is represented in base k, its 1111111 (no 0s) -> (n-1) has to be divisible by k
    if(n<7) cout << "NO" << endl;
    else {
        vector<ll> divi;
        for(ll i=2; i<=sqrt(n); i++) {
            if((n-1)%i==0) {
                divi.push_back(i);
                divi.push_back((n-1)/i);
                if(i==sqrt(n)) divi.pop_back();
            }
        }
        sort(all(divi));
        for(auto &x: divi) {
            ll cur = 0, temp = 0;
            if(n<x*(x+1)+1) break;
            while(true) {
                if(cur>=n) break;
                cur += pow(x, temp);
                temp++;
            }
            if(cur==n) {
                // cout << x << endl;
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}