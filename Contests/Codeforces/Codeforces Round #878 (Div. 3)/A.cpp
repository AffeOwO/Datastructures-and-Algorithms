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

    vector<char> idk;
    idk.push_back(s[0]);
    bool temp = false;
    for(int i=1; i<n; i++) {
        if(temp) {
            idk.push_back(s[i]);
            temp = false;
        }
        else if(s[i]==*idk.rbegin()) {
            temp = true;
        } 
    }


    for(auto &x: idk) cout << x;
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}