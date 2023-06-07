#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int query(string type, int a, int b) {
    cout << type << " " << a << " " << b << endl << flush;
    int ans;
    cin >> ans;
    return ans;
}

int sum(int a, int b) {
    int and_ = query("and", ++a, ++b);
    int or_ = query("or", a, b);
    int xor_ = ~and_ & or_;
    return 2 * and_ + xor_;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    int a_b = sum(0, 1);
    int a_c = sum(0, 2);
    int b_c = sum(1, 2);

    vector<int> nums{(a_b+a_c-b_c)/2};
    nums.push_back(a_b-nums[0]);
    nums.push_back(a_c-nums[0]);
    for(int i=3; i<n; i++) nums.push_back(sum(i-1, i) - nums.back());
    sort(all(nums));
    cout << "finish " << nums[k-1] << endl << flush;
}