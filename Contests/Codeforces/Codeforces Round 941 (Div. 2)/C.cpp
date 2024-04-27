#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

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
    sort(all(nums));
    // alice goes first; bob second

    vector<int> diffs = {nums[0]}; // diffs.size() = num of distinct elments in nums
    if(diffs[0]!=1) diffs[0] = 2;
    for(int i=1; i<n; i++) {
        if(nums[i]!=nums[i-1]) diffs.push_back(nums[i]-nums[i-1]);
        if(diffs.back()!=1) diffs.back() = 2;
    }
    /*
    pair<int, int> cnt; // .first = 1s, .second = 2s
    for(auto &x: diffs) {
        if(x==1) cnt.first++;
        else cnt.second++;
    }
    */

    // odd number of 1s -> alice 
    // even number of 1s -> bob
    // any number of 2s -> alice
    // odd number of 1s + any number of 2s -> bob
    // even number of 1s + any number of 2s -> alice
    // odd number of 1s + any number of 2s + odd number of 1s -> bob
    vector<pair<int, int>> blocks; // .first = length, .second = type
    pair<int, int> tmp = {1, diffs[0]};
    for(int i=1; i<diffs.size(); i++) {
        if(diffs[i]==tmp.second) tmp.first++;
        else {
            blocks.push_back(tmp);
            tmp = {1, diffs[i]};
        }
    }
    blocks.push_back(tmp);
    // cout << blocks.size() << " " << blocks[0].first << " " << blocks[0].second << endl;
    int sol = 0;
    vector<int> change;
    for(auto &x: blocks) {
        //cout << x.first << " " << x.second << endl;
        if(sol%2==0 and x.second==2) change.push_back(1);
        else if(sol%2==1 and x.second==2) change.push_back(0);
        if(x.second==2) sol += 1;
        else if(x.second==1 and x.first%2==1) sol += 1;
        else sol += 0;
    }
    sol %= 2;
    if(change.size()>0 and change[change.size()-1]!=sol) sol^=1;
    for(int i = change.size()-1; i>=0; i--) {
        if(change[i]!=sol) {
            sol^=1;
        }
    } 

    
    if(sol==1) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}