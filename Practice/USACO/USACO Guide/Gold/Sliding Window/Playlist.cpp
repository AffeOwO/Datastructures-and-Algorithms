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

    int n, sol = 1; cin >> n;   
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    map<int, int> cnt;
    int pnt = 0;
    for(int i=0; i<n; i++) {
        cnt[nums[i]]++;
        while(cnt[nums[i]]>1) {
            cnt[nums[pnt]]--;
            pnt++;
        }
        sol = max(i-pnt+1, sol);
    }

    cout << sol << endl;
}