#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int k, n; 
vector<ll> groups;

bool pos(ll cur) {
    // every c has k members (distinct group each member)
    // check if cur councils can be formed
    ll cnt = 0; // k*cur students needed and you can only take max cur students from each group
    for(auto &x: groups) cnt += min(x, cur);

    return cnt/k>=cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    groups.resize(n);
    for(auto &x: groups) cin >> x;

    ll l = 1, r = 5e10, m, s;
    while(l<=r) {
        m = (l+r)/2;
        if(pos(m)) {
            s = m;
            l = m+1;
        }
        else r = m-1;
    }   
    cout << s << endl;
}