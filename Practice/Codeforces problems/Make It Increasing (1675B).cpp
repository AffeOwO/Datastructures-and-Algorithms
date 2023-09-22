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
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    int cnt = 0;
    for(int i=n-2; i>=0; i--) {
        while(nums[i]>=nums[i+1]) {
            cnt++;
            nums[i] /= 2;
            if(nums[i] == 0) break;
        }
    }

    for(int i=1; i<n; i++) {
        if(nums[i] == 0) {
            cout << -1 << endl;
            return;
        }
    }
    cout << cnt << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}