#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    ll pnt = 0;
    map<int, ll> cnt;
    ll sol = 0;
    for(ll i=0; i<n; i++) {
        cnt[nums[i]]++;
        while(cnt.size()>k) {
            cnt[nums[pnt]]--;
            if(cnt[nums[pnt]]==0) cnt.erase(nums[pnt]);
            pnt++;
        }
        // i-pnt+1
        sol += i-pnt+1;
    }
    cout << sol << endl;
}