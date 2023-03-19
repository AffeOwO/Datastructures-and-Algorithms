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
    int n; cin>> n;
    string s; cin >> s;

    if(n==1 and s[0] != 'W') cout << "NO" << endl;
    else {
        pair<int, int> clrs;
        if(s[0] == 'B') clrs.first++;
        else if(s[1] == 'R') clrs.second++;
        if(s[n-1]=='B') clrs.first++;
        else if(s[n-1] == 'R') clrs.second++;
        for(int i=1; i<n-1; i++) {
            if(s[i]=='R') clrs.second++;
            else if(s[i]=='B')clrs.first++;
            if(s[i-1] == 'W' and s[i+1] == 'W' and s[i] != 'W') {
                cout << "NO" << endl;
                return;
            }

        }
        if((clrs.first >= 1 and clrs.second == 0) or (clrs.first ==0 and clrs.second >= 1)) cout << "NO" << endl;
        else cout << "YES" << endl;
    } 
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin>> t;
    while(t--) solve();
}