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
    string s; 
    for(int i=0; i<n; i++) {
        char temp; cin >> temp;
        if(temp=='0') s+= temp;
    }
    n = s.size();
    // Alice makes the first move
    if(n%2==0) cout << "BOB" << endl;
    else if(n>1 and n%2==1) cout << "ALICE" << endl;
    else cout << "BOB" << endl;
    
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}