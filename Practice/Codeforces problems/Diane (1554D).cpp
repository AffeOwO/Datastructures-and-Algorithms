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

string letters = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    int n; cin >> n;
    
    if(n<=26) {
        for(int i=0; i<n; i++) cout << letters[i];
        cout << endl;
        return;
    }
    // if x*n appears somewhere, then x*(n +/- 1) has to appear somewhere where x represents any char
    // mixed strings: 

    if(n%2==0) {
        for(int i=0; i<n/2; i++) cout << "a";
        cout << "b";
        for(int i=0; i<n/2-1; i++) cout << "a";
        cout << endl;
        return;
    }
    else {
        // n is odd
        // put an a at the end and a double a in the front
        for(int i=0; i<n/2-1; i++) cout << "a";
        cout << "bbcb";
        for(int i=0; i<n/2-2; i++) cout << "a";
        cout << endl;
        return;
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