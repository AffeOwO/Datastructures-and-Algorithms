#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<ll> nums(n); // 1-indexed
    ll sol = 0;
    ll maxi = -1e9-1, max_dif = 0;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        nums[i] = temp;
        if(temp>maxi) maxi = temp;
        max_dif = max(max_dif, maxi-temp); 
    }
    ll cur = 1;
    while(cur-1<max_dif) {
        sol++;
        cur*=2;
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