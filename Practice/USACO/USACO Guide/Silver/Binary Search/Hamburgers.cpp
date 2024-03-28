#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll nb, ns, nc, pb, ps, pc, r, ab = 0, as = 0, ac = 0; 

bool p(ll cur) {
    // implement
    ll mb = max(cur*ab - nb, (ll)0), ms = max(cur*as - ns, (ll)0), mc = max(cur*ac - nc, (ll)0);
    ll cnt = pb*mb + ps*ms + pc*mc;
    return cnt<=r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    for(auto &x: s) {
        switch(x) {
            case 'B': 
                ab++;
                break;
            case 'S':
                as++;
                break;
            default: ac++;
        }
    }

    ll idk = 0;
    if(ab!=0) idk = nb/ab;
    if(as!=0) idk = min(idk, ns/as);
    if(ac!=0) idk = min(idk, ns/ac);
    nb -= ab*idk; ns -= as*idk; nc -= ac*idk;

    ll l = 0, r = 1e15, m, sl = 0;
    while(l<=r) {
        m = (l+r)/2;
        if(p(m)) {
            l = m+1;
            sl = m;
        }
        else r = m-1;
    }
    //cout << sl << " " << idk << endl;
    cout << sl+idk << endl;
}