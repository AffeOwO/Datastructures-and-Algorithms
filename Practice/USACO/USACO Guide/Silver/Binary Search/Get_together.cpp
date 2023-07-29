#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<double, double>> idk(n);
    for(auto &x: idk) cin >> x.first >> x.second;
 
    double left = 0, right = 2e9, sol = 0;
    for(int i=0; i<60; i++) {
        double mid = (left+right)/2;

        double mini = 1e9, maxi = -1e9;
        for(int j=0; j<n; j++) {
            double temp = idk[j].second*mid;
            mini = min(mini, idk[j].first+temp);
            maxi = max(maxi, idk[j].first-temp);
        }

        if(mini>maxi) {
            sol = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << setprecision(10) << sol << endl;
}