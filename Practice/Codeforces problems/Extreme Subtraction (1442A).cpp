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
    
    int pnt = 1e6, pnt2 = 0;
    for(int i=0; i<n; i++) {
        if(min(nums[i]-pnt2, pnt)<0) {
            cout << "NO" << endl;
            return;
        }
        pnt = min(nums[i]-pnt2, pnt);
        pnt2 = nums[i] - pnt;
    }
    cout << "YES" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}