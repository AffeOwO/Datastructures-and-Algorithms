#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

void solve() {
    int n, m; cin >> n >> m;
    if(n>m || (n%2==0 && m%2==1)) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        if(n%2==1) {
            for(int i=0; i<n-1; i++) {
                cout << 1 << " ";
            }
            cout << m-n+1 << endl;
        }
        else {
            for(int i=0; i<n-2; i++) {
                cout << 1 << " ";
            }
            cout << (m-n)/2+1 << " " << (m-n)/2+1 << endl;
        }
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }
}