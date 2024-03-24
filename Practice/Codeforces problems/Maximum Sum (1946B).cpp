#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll binexp(int idk) {
    if(idk==0) return 1;
    else if(idk==1) return 2;
    
    if(idk%2==0) {
        ll temp = binexp(idk/2);
        return (temp*temp)%MOD;
    }
    else {
        ll temp = binexp(idk/2);
        return (((temp*temp)%MOD)*2)%MOD;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    
    ll maxi = 0, temp = 0, bruh = 0;
    for(int i=0; i<n; i++) {
        bruh += nums[i];
        temp += nums[i];
        maxi = max(maxi, temp);
        if(temp<0) temp = 0;
    }
    maxi%=MOD;
    ll sol = (bruh+maxi*(binexp(k)-1))%MOD;
    cout << (sol+MOD)%MOD << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}