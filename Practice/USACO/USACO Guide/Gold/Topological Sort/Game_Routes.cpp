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
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> ind(n);
    vector<vector<int>> edges(n), back_e(n);   
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ind[b]++;
        edges[a].push_back(b);
        back_e[b].push_back(a);
    }
    vector<ll> dp(n); dp[0] = 1;
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(ind[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x: back_e[cur]) {
            if(dp[x]>0) dp[cur] = (dp[cur]+dp[x])%MOD;
        }
        for(auto &x: edges[cur]) {
            ind[x]--;
            if(ind[x]==0) q.push(x);
        }
    }
    if(dp[n-1]<0) cout << 0 << endl;
    else cout << dp[n-1]%MOD << endl;
}