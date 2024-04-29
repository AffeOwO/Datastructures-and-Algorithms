#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    string s; cin >> s;
    ll cnt = 0, n = s.size(); // cnt of 1s
    for(auto &x: s) cnt += (x=='1');
    ll sol = 0;


    ll pnt = 0, cnt1 = 0;
    for(int i=0; i<n; i++) {
        
        if(s[i]=='1') {
            cnt1++;
        }
        else {
            if(cnt1!=0) sol += (cnt1+1);
        }
    }
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}