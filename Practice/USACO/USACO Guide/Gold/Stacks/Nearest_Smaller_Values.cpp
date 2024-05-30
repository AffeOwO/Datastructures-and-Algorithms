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
    vector<int> nums(n), sol(n);
    for(auto &x: nums) cin >> x;
    stack<pair<int, int>> s;
    for(int i=0; i<n; i++) {
        while(!s.empty()) {
            if(s.top().first<nums[i]) {
                sol[i] = s.top().second;
                break;
            }
            s.pop();
        }
        s.push(make_pair(nums[i], i+1));
    }


    for(auto &x: sol) cout << x << " ";
}