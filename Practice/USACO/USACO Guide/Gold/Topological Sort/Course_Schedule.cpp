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

vector<int> sol, ind;
vector<bool> visited;
vector<vector<int>> edges;

void topo(int v) {
    visited[v] = true;
    for(auto &x: edges[v]) {
        if(!visited[x]) topo(x);
    }
    sol.push_back(v);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, pnt = 0; cin >> n >> m;
    edges.resize(n); visited.resize(n); ind.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
    }
    stack<int> s;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            topo(i);
        }
    }
    reverse(all(sol));
    for(int i=0; i<n; i++) ind[sol[i]] = i;

    for(int i=0; i<n; i++) {
        for(auto &x: edges[i]) {
            if(ind[x]<ind[i]) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(auto &x: sol) cout << x+1 << " ";
    cout << endl;
}