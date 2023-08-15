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

    int n; cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    ll sol = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i+=2) {
        pq.push(nums[i]); pq.push(nums[i+1]);
        pq.pop();
    }
    while(!pq.empty()) {
        sol += pq.top();
        pq.pop();
    }

    cout << sol << endl;
}

/*
int cur = 0, temp = 0;
    for(int i=0; i<n/2; i++) {
        while(used.count(nums[i+temp].second)) temp++;
        sol += nums[i+temp].first;
        while(used.count(cur)) cur++;
        used.insert(cur);
        cur++;
    }

vector<pair<ll, int>> nums(n);
    set<int> used;
    for(int i=0; i<n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(all(nums), cstm);
    //for(auto &x: nums) cout << x.first << " " << x.second << endl;

bool cstm(pair<ll, int> p1, pair<ll, int> p2) {
    if(p1.first == p2.first) return p1.second<p2.second;
    return p1.first>p2.first;
}
*/