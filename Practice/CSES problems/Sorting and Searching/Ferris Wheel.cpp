#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    int children[n];
    for(int i=0; i<n; i++) {
        cin >> children[i];
    }

    int sol = 0;
    sort(children, children+n);

    int cur = 0;
    for(int i=n-1; i>=0; i--) {
        if(i<cur) {
            break;
        }

        if(children[i] + children[cur] <= x) {
            cur += 1;
        }
        sol += 1;
    }

    cout << sol << "\n";
}