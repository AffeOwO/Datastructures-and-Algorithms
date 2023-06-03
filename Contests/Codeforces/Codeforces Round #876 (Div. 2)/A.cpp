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
    int n, k; cin >> n >> k;
    // if k bigger than sol bigger
    // if k=1, then sol=n
    // array is symmetric
    int sol = 0;
    int last;
    for(int i=0; i<n/2; i++) {
        if(i%k==0) {
            sol+=2;
            last = i+1;
        }
    }
    if(n-2*last>=k) sol++;
    
    
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}