#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll n;

ll check(ll cur) {
    ll ret = 0;
    for(ll i=1; i<=n; i++) ret += min(n, cur/i);

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    ll l = 1, r = n*n;
    while(l<r) {
        ll mid = (l+r)/2;
        if(check(mid)>=(n*n+1)/2) r = mid;
        else l = mid+1;
        //cout << l << " " << r << " " << mid << " " << check(mid) << endl;
    }
    cout << l << endl;
}