#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int cnt = 0;
    for(int i=0; i<size(s)-1; i++) {
        if(s[i] == s[i+1]) {
            cnt += 1;
        }
    }
    if(s[size(s)-1] == t[size(t)-1]) {
        cnt += 1;
        }
    for(int i=0; i<size(t)-1; i++) {
        if(t[size(t) - 1 - i] == t[size(t) - 2- i]) {
            cnt += 1;
        }
    }
    if(cnt <= 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test;
    cin >> test;
    for(;test>0; test--) {
        solve();
    }
}