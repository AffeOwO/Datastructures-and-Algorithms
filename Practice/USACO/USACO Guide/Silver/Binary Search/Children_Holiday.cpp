#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

struct helper {
    ll t, z, y;  // time, bloons, rest
};

ll m, n;
vector<helper> helpers;

ll blown(helper idk, ll time) {
    ll bloons = idk.z*(time/(idk.t*idk.z+idk.y));
    ll temp = time%(idk.t*idk.z+idk.y);
    if(temp>=idk.t*idk.z) bloons += idk.z;
    else bloons += temp/idk.t;
    return bloons;
}

bool check(ll time) {
    ll cur = 0;
    for(auto &x: helpers) cur += blown(x, time);
    return cur >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;  // m baloons and n assistants
    helpers.resize(n);
    for(auto &x: helpers) cin >> x.t >> x.z >> x.y;

    ll left = -1, right = 1e9, mid;
    while(left+1<right) {
        mid = (left+right)/2;
        if(check(mid)) {
            right = mid;
        }
        else left = mid;
    }
    cout << right << endl;
    for(auto &x: helpers) {
        ll cur = blown(x, right);
        cout << min(m, cur) << " ";
        m -= min(m, cur);
    }
    cout << endl;
}