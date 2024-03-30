#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> nums(n);
    for(auto &x: nums) cin >> x.first;
    for(int i=0; i<n; i++) nums[i].second = i; // if you win against opponent i, then lower this number by 1
    sort(all(nums));
    
    int pnt=0, maxi = 0;;
    for(int i=0; i<n; i++) {
        if(m-nums[i].first<0) break;
        pnt = i+1;
        m -= nums[i].first;
        maxi = max(maxi, nums[i].first);
    }
    // pnt wins; if you win against opponent pnt, then you have place n-pnt else n-pnt+1
    for(int i=0; i<n; i++) {
        if(nums[i].second==pnt) {
            if(i<pnt) cout << n - pnt << endl;
            else {
                m += maxi;
                if(nums[i].first<=m) cout << n-pnt << endl;
                else cout << n-pnt+1 << endl;
            }
            return;
        }
    }
    if(pnt==n) cout << 1 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}