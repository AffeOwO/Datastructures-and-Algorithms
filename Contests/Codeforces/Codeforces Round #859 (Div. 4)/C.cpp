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
    map<char, int> hashy;
    string s; cin>>s;
    bool sol = true;
    for(int i=0; i<n; i++) {
        if(hashy[s[i]] == 0) {
            if(i%2==0) hashy[s[i]] = 1;
            else hashy[s[i]] = -1;
        }
        else if(hashy[s[i]] == 1 && i%2==1) sol = false;
        else if(hashy[s[i]] == -1 && i%2==0) sol = false;
    }
    if(sol) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}