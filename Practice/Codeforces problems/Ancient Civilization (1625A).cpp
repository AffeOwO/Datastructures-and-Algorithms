#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, l; cin >> n >> l;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    // x < 2^l, length l in base 2
    // find y such that the sum of bits(y^x_i) is minimized
    vector<int> sol(l);
    for(auto &x: nums) {
        bitset<32> idk(x);
        for(int i=0; i<l; i++) {
            if(idk.test(i)) sol[i]++;
            else sol[i]--;
        }
    }
    int res = 0;
    for(int i=0; i<l; i++) {
        if(sol[i]>=0) res += (1<<i);
    }
    cout << res << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}