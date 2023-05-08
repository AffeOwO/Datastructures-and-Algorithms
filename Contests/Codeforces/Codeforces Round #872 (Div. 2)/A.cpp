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
    string s; cin >> s;
    int n = s.size();
    set<char> cnt;
    for(int i=0; i<n; i++) {
        cnt.insert(s[i]);
    }
    if(cnt.size()==1) cout << -1 << endl;
    else if(n%2==1) cout << n-1 << endl;
    else {
        cout << n-1 << endl;
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