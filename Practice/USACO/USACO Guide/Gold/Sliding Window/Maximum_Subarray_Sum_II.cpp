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

    int n, a, b; cin >> n >> a >> b;
    vector<ll> nums(n), pref(n+1);
    for(auto &x: nums) cin >> x; 
    for(int i=1; i<=n; i++) {
        pref[i] += pref[i-1];
        pref[i] += nums[i-1];
    }
    // i-a; i-b
    multiset<ll> s;
    ll sol = pref[a];
    for(int i=0; i<n; i++) {
        if(i>=a-1) s.insert(pref[i-a+1]);
        if(i>=b) s.erase(s.find(pref[i-b]));
        if(!s.empty()) sol = max(pref[1+i]-*s.begin(), sol);
    }


    cout << sol << endl;
}