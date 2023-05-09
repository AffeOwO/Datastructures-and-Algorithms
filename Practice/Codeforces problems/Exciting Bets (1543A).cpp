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
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll a, b; cin >> a >> b;
    if(a==b) cout << "0 0" << endl;
    // conjecture: maximum gcd = abs(a-b)
    else {
        cout << abs(a-b) << " ";
        ll temp = a%abs(a-b);
        cout << min(temp, abs(a-b)-temp) << endl;
    }

}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}