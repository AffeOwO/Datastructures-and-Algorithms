#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
 
void solve() {
    int n, k; cin >> n >> k;
    int cnt = 1;
    vector<int> nums, sortednums(n);
    for(auto &x: sortednums) cin >> x;
    nums = sortednums;
    sort(all(sortednums));
    
    for(int i=1; i<n; i++) {
        if(nums[i-1] == sortednums[n-1]) cnt++;
        else {
            int left = 0, right = n-2;
            int mid;
            while(left<=right) {
                mid = (left+right)/2;
                if(sortednums[mid]==nums[i-1]) break;
                else if(sortednums[mid]<nums[i-1]) left = mid+1;
                else right = mid-1;
            }
            if(nums[i] != sortednums[mid+1]) cnt++;
        }
    }

    if(cnt>k) cout << "No" << endl;
    else cout << "Yes" << endl;
}
 
int main() {
    //ifstream fin("");
    //ofstream fout("");
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}