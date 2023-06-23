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
    
    ll n, x, y; cin >> n >> x >> y;
    // at the start you have 1 copy, to use both copiers, you need two papers (min(x, y) seconds)
    ll temp = min(x, y);
    n--; // now you have 2 copies
    ll left = 0, right = max(x, y) * n;
    ll sol = 0;
    while(left<=right) {
        ll mid = right - (right-left)/2;
        ll cur = mid/x + mid/y;
        if(cur>=n) {
            sol = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << sol+temp << endl;
}