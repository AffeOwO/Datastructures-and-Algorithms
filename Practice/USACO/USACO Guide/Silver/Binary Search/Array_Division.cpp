#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll n, k;
vector<ll> nums;

bool check(ll val) {
    int partitions = 1;
    ll cur_sum = 0;
    for(int i=0; i<n; i++) {
        //if(val==7) cout << partitions << " " << cur_sum << " " << i << endl;
        if(cur_sum+nums[i]>val) {
            partitions++;
            cur_sum = nums[i];
        } 
        else cur_sum += nums[i];
    }
    return partitions <= k;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll maxi = 0, sum = 0; cin >> n >> k;
    nums.resize(n);
    for(auto  &x: nums) {
        cin >> x;
        sum += x;
        maxi = max(maxi, x);
    }
    ll left = maxi, right = sum, sol = maxi;
    while(left<=right) {
        ll mid = (left+right)/2;
        if(check(mid)) {
            sol = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << sol << endl;
}