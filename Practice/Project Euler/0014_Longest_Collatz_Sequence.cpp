#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll sol = 1;
    vector<ll> cache(1e8, -1); // cache[i+1] = length
    cache[0] = 1;
    for(ll i=2; i<1e6; i++) {
        vector<ll> route = {i};
        ll cur = i;
        while(true) {
            if(cur%2 == 0) cur /= 2;
            else cur = 3*cur + 1;
            if(cur-1<1e8 and cache[cur-1] != -1) {
                sol = max((ll)(cache[cur-1] + route.size()), sol);
                for(int j=0; j<route.size(); j++) {
                    if(route[j]-1<1e8) cache[route[j]-1] = cache[cur-1]+route.size()-j;
                }
                break;
            }
            route.push_back(cur);
        }
    }
    cout << sol << endl;
}