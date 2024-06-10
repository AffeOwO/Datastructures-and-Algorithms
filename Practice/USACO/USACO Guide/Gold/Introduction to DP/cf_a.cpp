#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

int main() {
    ifstream fin("ladder.in");
    ofstream fout("ladder.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; fin >> n;
    vector<int> a(n), dp(n+1);
    for(auto &x: a) fin >> x;
    dp[1] = a[0];
    for(int i=2; i<=n; i++) dp[i] = max(dp[i-1]+a[i-1], dp[i-2]+a[i-1]);
    fout << dp[n] << endl;
}