#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 998244353

void solve() {
    ll n; cin >> n;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    ll sol = 0;

    vector<vector<ll>> bity(n, vector<ll>(31)), prefbit(31, vector<ll>(n+1));
    for(int i=0; i<n; i++) {
        sol = (sol+nums[i])%MOD;
        for(int j=0; j<31; j++) bity[i][j] = ((nums[i]>>j)&1);
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<31; j++) prefbit[j][i] = (prefbit[j][i-1]+bity[i-1][j])%2;
    }

    for(int i=0; i<31; i++) {
        pair<ll, ll> pz, po; // .second = cnt
        for(int j=1; j<=n; j++) {
            pz.first = (pz.first+pz.second)%MOD;
            po.first = (po.first+po.second)%MOD;
            if(prefbit[i][j]==1) sol = (sol+(pz.first+pz.second)*(1<<i))%MOD;
            else sol = (sol+(po.first+po.second)*(1<<i))%MOD;
            if(prefbit[i][j-1]==0) pz.second++;
            else po.second++;
            //cout << pz.first << " " << pz.second << " " << po.first << " " << po.second << " " << sol << "---";
        }
        //cout << endl;
    }

    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}