#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

pair<ll, ll> colors; // .first = blue, .second = red
vector<vector<ll>> edges;
vector<ll> nodes; // 0 = unvisited, 1 = blue, 2 = red

void dfs(ll node, int prev) {
    if(nodes[node] != 0) return;
    nodes[node] = 2-prev;
    if(prev==1) colors.first++;
    else colors.second++;
    for(auto &x: edges[node])  dfs(x, prev^1);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    edges.resize(n);
    nodes.resize(n);
    for(int i=0; i<n-1; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(0, 1);

    ll sol = 0;
    for(int i=0; i<n; i++) {
        if(nodes[i]==2) continue;
        sol += (colors.second - edges[i].size());
    }
    cout << sol << endl;
}