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

    int t; cin >> t;
    while(t--) {
    int n, k; cin >> n >> k;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    sort(all(nums));
    if(k>=3) cout << 0 << endl;
    else if(k==2) {
        vector<ll> idk;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) idk.push_back(nums[j]-nums[i]);
        }
        sort(all(idk));
        ll cur = min(idk[0], nums[0]), m = idk.size();
        int ind = 1;
        for(int i=0; i<m; i++) {
            while(ind<n-1 and nums[ind]<idk[i]) ind++;
            cur = min({cur, abs(nums[ind-1]-idk[i]), abs(nums[ind]-idk[i])});
        }
        cout << cur << endl;
    }
    else {
        vector<ll> idk;
        idk.push_back(nums[0]);
        for(int i=0; i<n-1; i++) idk.push_back(nums[i+1]-nums[i]);
        sort(all(idk));
        cout << idk[0] << endl;;
    }
    }
}