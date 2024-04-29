#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    vector<ll> cnt(n, 1);
    for(int i=0; i<k; i++) {
        pair<ll, ll> diff = {0, 0};
        bool tmp = false; // false = left; true = right
        for(ll j=0; j<n; j++) {
            if(j!=0 and ((nums[j-1]-nums[j])*(cnt[j-1]))>diff.first) {
                diff = {(nums[j-1]-nums[j])*(cnt[j-1]), j};
                tmp = false;
            }
            if(j!=n-1 and ((nums[j+1]-nums[j])*(cnt[j+1]))>diff.first) {
                diff = {(nums[j+1]-nums[j])*(cnt[j+1]), j};
                tmp = true;
            }
        }
        if(diff.first == 0) break;
        if(!tmp) {
            cnt[diff.second]++;
            for(int h=0; h<cnt[diff.second-1]; h++) {
                cnt[diff.second-1-h]++;
                nums[diff.second-1-h] -= nums[diff.second]; 
            }
        }
        else {
            cnt[diff.second]++;
            for(int h=0; h<cnt[diff.second+1]; h++) {
                cnt[diff.second+1+h]++;
                nums[diff.second+1+h] -= nums[diff.second];
            }
        }
    }

    ll sol = 0;
    for(auto &x: nums) sol += x;
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}