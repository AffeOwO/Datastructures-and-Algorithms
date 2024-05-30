#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
    if(p1.second==p2.second) return p1.first>p2.first;
    return p1.second<p2.second;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> nums(n), sol(n);
    for(auto &x: nums) cin >> x;
    vector<pair<ll, ll>> borders(n, make_pair(0, n)), tmp(n);
    stack<pair<ll, ll>> s;
    for(int i=0; i<n; i++) {
        while(!s.empty()) {
            if(s.top().first<nums[i]) {
                borders[i].first = s.top().second;
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
                borders[i].second = s.top().second;
                break;
            }
            s.pop();
        }
        s.push(make_pair(nums[i], i));
    }
    for(int i=0; i<n; i++) tmp[i] = make_pair(nums[i], borders[i].second-borders[i].first);
    sort(all(tmp), comp);
    stack<pair<int, int>> s2;
    for(int i=n-1; i>=0; i--) {
        if(s2.empty() or s2.top().first<=tmp[i].first) s2.push(tmp[i]);
    }

    for(int i=0; i<n; i++) {
        while(i+1>s2.top().second) s2.pop();
        sol[i] = s2.top().first;
    }

    for(auto &x: sol) cout << x << " ";
    cout << endl;   
}