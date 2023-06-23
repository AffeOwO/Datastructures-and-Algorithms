#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; ll c, d; cin >> n >> c >> d;  // remove = c, add = d
    vector<ll> nums;
    set<ll> appeared;
    ll sol = 0;
    for(int i=0; i<n; i++) {
        ll val; cin >> val;
        if(appeared.count(val)) sol += c;
        else {
            appeared.insert(val);
            nums.push_back(val);
        }
    }
    sort(all(nums));
    // initial = remove all
    ll cur = (nums.size())*c;
    if(nums[0]==1) cur -= c;
    else cur += d;
    ll temp = cur;
    // for(auto &x: nums) cout << x << " ";
    // cout << endl;
    for(int i=0; i<nums.size(); i++) {
        if(i==0) {
            if(nums[i] != 1) {
                temp -= c;
                temp += (nums[i]-2)*d;    
            }
        }
        else {
            temp -= c;
            temp += ((nums[i]-nums[i-1]-1)*d);
        }
        cur = min(cur, temp);
    }
    cout << cur+sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}