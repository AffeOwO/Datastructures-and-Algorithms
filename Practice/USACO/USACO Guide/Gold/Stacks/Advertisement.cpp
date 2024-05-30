#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n; cin >> n;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;

    ll sol = nums[0];
    vector<pair<ll, ll>> border(n, make_pair(0, n));
    stack<pair<ll, ll>> s;
    for(int i=0; i<n; i++) {
        while(!s.empty()) {
            if(s.top().first<nums[i]) {
                border[i].first = s.top().second;
                break;
            }
            s.pop();
        }
        s.push(make_pair(nums[i], i+1));
    }
    while(!s.empty()) s.pop();
    for(int i=n-1; i>=0; i--) {
        while(!s.empty()) {
            if(s.top().first<nums[i]) {
                border[i].second = s.top().second;
                break;
            }
            s.pop();
        }
        s.push(make_pair(nums[i], i));
    }

    //for(auto &x: border) cout << x.first << " " << x.second << endl;

    for(int i=0; i<n; i++) sol = max(sol, (border[i].second-border[i].first)*nums[i]);
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}