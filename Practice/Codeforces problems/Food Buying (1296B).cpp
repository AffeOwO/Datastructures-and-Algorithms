#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int s;
    cin >> s;
    int sol = 0;
    int pw = 1000 * 1000 * 1000;
    while (s > 0) {
		while (s < pw) pw /= 10;
			sol += pw;
			s -= pw - pw / 10;
		}
    cout << sol << "\n";
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