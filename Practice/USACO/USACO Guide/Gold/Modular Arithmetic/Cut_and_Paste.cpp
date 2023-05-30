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
    int x; cin >> x;
    string s; cin >> s;
    /*
    l=0 at the start, cursor is left to s_l; 0-indexed

    while (l!=x) {
        l++;
        cut(); // cut the string right to l
        for(s[l-1]) paste(); // paste the cut out part
    }
    */
    // probably brute-force since x is small and you dont have to simulate the whole string, just the first x chars
    ll length = s.size(); // additional 
    for(ll l=1; l<=x; l++) {
        // the s[l-1] character wont change -> keep s as original string and only let the length var become bigger or can it?

        ll cut_out = length-l;

        for(int i=1; i<s[l-1]-'0'; i++) {
            length = (length + cut_out + (ll)MOD) % MOD; 
            if(s.size()<x) s += s.substr(l, cut_out);
        } 
    }


    cout << length%MOD << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}