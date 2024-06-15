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
 
int n, m; 
vector<int> ind;
vector<vector<int>> edges, back_e;
 
int main() {
    //ifstream fin("");
    //ofstream fout("");
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    ind.resize(n); edges.resize(n); back_e.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ind[b]++;
        edges[a].push_back(b);
        back_e[b].push_back(a);
    }
 
    vector<pair<int, int>> dp(n, make_pair(-2e9, -1)); dp[0] = {1, -1};
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(ind[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x: back_e[cur]) {
            if(dp[cur].first<dp[x].first+1 and dp[x].first>0) {
                dp[cur].first = dp[x].first+1;
                dp[cur].second = dp[x].second;
                dp[cur].second = x;
            }
        }
        for(auto &x: edges[cur]) {
            ind[x]--;
            if(ind[x]==0) q.push(x);
        }
    }
    if(dp[n-1].first<0) cout << "IMPOSSIBLE" << endl;
    else{
        cout << dp[n-1].first << endl;
        vector<int> sol;
        int cur = n-1;
        while(cur!=-1) {
            sol.push_back(cur+1);
            cur = dp[cur].second;
        }
        reverse(all(sol));
        for(auto &x: sol) cout << x << " ";
        cout << endl;
    }
}