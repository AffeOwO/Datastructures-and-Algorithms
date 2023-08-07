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
    int sol = 1, cur = INT_MAX, prev = 1, cnt = 0;
    for(int i=1; i<n; i++) {
        if(nums[i]<cur) {
            if(prev == 0) {
                sol++;
                prev = cnt;
                cnt = 0;
            }
            prev--;
        }
        cnt++;
        cur = nums[i];
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