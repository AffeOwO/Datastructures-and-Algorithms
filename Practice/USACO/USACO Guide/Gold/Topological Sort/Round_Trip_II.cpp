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

vector<int> sol = {-1}, ind, visited;
vector<vector<int>> edges;

void topo(int node, vector<int> &p) {
    p.push_back(node);
    if(visited[node]) {
        bool tmp = false;
        if(sol.size()==1) {
            sol.pop_back();
            for(int i=0; i<p.size(); i++) {
                if(node==p[i]) tmp = true;
                if(tmp) sol.push_back(p[i]);
            }
        }
        return;
    }
    visited[node] = 1;
    for(auto &x: edges[node]) {
        if(visited[x]!=2) topo(x, p);
    }
    p.pop_back();
    visited[node] = 2;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    edges.resize(n); visited.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
    }

    vector<int> tmp;
    for(int i=0; i<n; i++) {
        if(!visited[i]) topo(i, tmp);
    }

    if(sol.size()==1) cout << "IMPOSSIBLE" << endl;
    else {
        cout << sol.size() << endl;
        for(auto &x: sol) cout << x+1 << " ";
        cout << endl;
    }
}