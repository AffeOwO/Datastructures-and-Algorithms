#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll n, val0 = 0;
vector<vector<ll>> edges;
vector<ll> children, sol;

void dfs(ll node, ll prev) {
    for(auto &x: edges[node]) {
        if(x!=prev) {
            dfs(x, node);
            children[node] += children[x] + 1;
        }
    }
    val0 += children[node];
}

void dfs2(ll node, ll prev, ll curval) {
    sol[node] = curval;
    for(auto &x: edges[node]) {
        if(prev!=x) {
            ll temp = curval + n - 2 * (children[x]+1);
            dfs2(x, node, temp);
        }
    }
}

void solve() {
    cin >> n;
    edges.resize(n);
    for(ll i=1; i<n; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    children.resize(n); sol.resize(n);
    
    dfs(0, 0);
    
    dfs2(0, 0, val0);

    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}