#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll a, b, r; cin >> a >> b >> r;
    if(a==b) {
        cout << 0 << endl;
        return;
    }
    else if(a>b) {
        ll temp = a;
        a = b; b = temp;
    }
    // find x such that 0<=x<=r which minimizes abs((a xor x) - (b xor x))
    bitset<60> sa(a), sb(b); // sa.test(0) is the first bit = 2^0
    ll sol = b - a, cur = 0;
    for(ll i=59; i>=0; i--) {
        //cout << sb.test(i) << sa.test(i) << " ";
        if(sb.test(i)!=sa.test(i) and sb.test(i) and ((ll)2<<i)<sol and cur+((ll)1<<i)<=r) {
            cur += ((ll)1<<i);
            sol -= ((ll)2<<i);
            //cout << cur << " " << sol << endl;
        }
    }
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}