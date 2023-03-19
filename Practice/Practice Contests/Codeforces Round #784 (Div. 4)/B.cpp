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
    map<int, int> cnt;
    int n; cin >> n;
    bool done = false;
    int idk;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        cnt[temp]++;
        if(cnt[temp]==3) {
            done = true;
            idk = temp;
        }
    }
    if(done) cout << idk << endl;
    else cout << -1 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}