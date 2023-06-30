#include <bits/stdc++.h>

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
    if(n%2) {
        cout << "NO" << endl;
        return;
    }
    bool idk = true;
    for(int i=0; i<n/2; i++) {
        if(s[i] != s[i+n/2]) idk = false;
    }

    if(idk) cout << "YES" << endl;
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