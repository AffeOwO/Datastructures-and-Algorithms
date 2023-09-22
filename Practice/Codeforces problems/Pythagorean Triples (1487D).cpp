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
    // 1 <= a <= b <= c <= n
    // c+b = a^2 and a^2 + b^2 = c^2 -> c+b = c^2 - b^2 -> c-b = 1
    // -> a^2 = 2b + 1 and c = b+1
    int ans = 0;
    for (int i = 3; i * i <= 2 * n - 1; i += 2) {
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}