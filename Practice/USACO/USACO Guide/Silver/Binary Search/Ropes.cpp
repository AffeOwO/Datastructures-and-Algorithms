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
    
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;

    double sol = 0;
    double left = 0, right = 1e8;   
    for(int i=0; i<100; i++) {
        double mid = (left+right)/2;
        //cout << mid << endl;
        // mid = length
        ll cur = 0;
        for(auto &x: nums) cur += (ll)floor(x/mid);
        if(cur>=k) {
            sol = mid;
            left = mid;
        }
        else right = mid;
    }
    cout << setprecision(10) << sol << endl;
}