#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end();
#define MOD 1000000007;

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    // if multiple (x, y), return (x, y) with the smallest x possible
    // x^2 + 2xy + x = n - 1
    n--;
    if(n%2==1 || n == 0) cout << "NO" << endl;
    else {
        // bruteforce ?
        for(ll x=1; x<=n; x++) {
            ll y = (n - x*x - x) / (2*x);
            if(y<=0) {
                cout << "NO" << endl;
                break;
            }
            if((n - x*x - x) % (2*x) == 0) {
                cout << x << " " << y << endl;
                break;
            }
        }
    }
}