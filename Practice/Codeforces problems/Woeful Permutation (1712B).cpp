#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    if(n%2==0) {
        for(int i=1; i<=n; i++) {
            if(i%2==1) {
                cout << i+1 << " ";
            }
            else {
                cout << i-1 << " ";
            }
        }
        cout << "\n";
    }
    else {
        cout << 1 << " ";
        for(int i=1; i<=n-1; i++) {
            if(i%2==1) {
                cout << i+2 << " ";
            }
            else {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}