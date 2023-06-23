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
    
    double n; cin >> n; // find x such that x² + sqrt(x) = n with max error of 1e-6
    double left = 0, right = 1e5, mid;
    for(int i=0; i<100; i++) {
        mid = (left+right)/2;
        if(mid*mid+sqrt(mid)>=n) right = mid;
        else left = mid;
    }
    cout << setprecision(10) << mid << endl;
}