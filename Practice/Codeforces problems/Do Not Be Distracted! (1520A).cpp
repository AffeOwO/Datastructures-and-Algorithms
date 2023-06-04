#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    set<char> started;
    started.insert(s[0]);
    for(int i=1; i<n; i++) {
        if(started.count(s[i]) and s[i-1]!=s[i]) {
            cout << "NO" << endl;
            return;
        }
        started.insert(s[i]);
    } 
    cout << "YES" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}