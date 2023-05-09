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
    int n; cin >> n;
    pair<int, int> parity;
    for(int i=0; i<2*n; i++) {
        int temp; cin >> temp;
        if(temp%2==0) parity.first++;
        else parity.second++;
    }
    if(parity.first==parity.second) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}