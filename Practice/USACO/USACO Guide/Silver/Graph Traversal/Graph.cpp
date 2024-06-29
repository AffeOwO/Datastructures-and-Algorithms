#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<pair<int, int>>> edges; // .first = endpoint; .second = weigth
vector<int> visited, cur_comp;
vector<double> sol;
bool possible;

// find components
void dfs_1(int node) {
    if(visited[node]) return;
    visited[node] = true;
    cur_comp.push_back(node);
    for(auto &x: edges[node]) dfs_1(x.first);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    edges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c; // a connects b with edge of color c (1 = black; 2 = red) = sum of endpoints
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    // maybe we can get rid of this later
    for(int i=0; i<n; i++) {
        sort(all(edges[i]));
        // check if double edge with different weigth
        for(int j=1; j<edges[i].size(); j++) {
            if(edges[i][j-1].first == edges[i][j].first and edges[i][j-1].second != edges[i][j].second) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    // each component of the graph can be looked at seperatly
    visited.resize(n); sol.resize(n);
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            cur_comp.clear();
            dfs_1(i); // mark all nodes from this component as visited
            possible = true;
            if(edges[i].size() == 0) {
                sol[i] = 0;
                continue;
            }
            // test if component will work
            /*
            cycles of length 3 -> 1 value is easy to get
            */
            


            if(!possible) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}