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

bool is_pal(string bruh) {
    int n = bruh.length();
    for(int i=0; i<n/2; i++) {
        if(bruh[i] != bruh[n-i-1]) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<string> idk;
    for(int i=0; i<2*n-2; i++) {
        string temp; cin >> temp;
        if(temp.length() == n-1) idk.push_back(temp);
    }
    string lol;
    if(idk[0].substr(0, n-2) == idk[1].substr(1, n-2)) {
        lol = idk[1]+idk[0].substr(n-2,1);
    }
    else {
        lol = idk[0]+idk[1].substr(n-2,1);
    }
    if(is_pal(lol)) cout << "YES" << endl;
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