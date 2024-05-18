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

int n, m, cnt = 1; 
vector<int> pos, visited;
vector<vector<int>> edges;
vector<pair<int, int>> sol;

/*
void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    components.back().push_back(node);
    for(auto &x: edges[node]) dfs(x);
}*/

void dfs(int node, int par = -1) {
    visited[node] = cnt++;
    for(auto &x: edges[node]) {
        if(x!=par) {
            if(!visited[x]) {
                dfs(x, node);
                if(pos[x]) {
                    pos[x] = 0;
                    sol.push_back({x, node});
                }
                else {
                    sol.push_back({node, x});
                    pos[node] ^= 1;
                }
            }
            else if(visited[node]>visited[x]) {
                sol.push_back({node, x});
                pos[node] ^= 1;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    edges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    visited.resize(n); pos.resize(n);
    for(int i=0; i<n; i++) {
        if(!visited[i]) dfs(i);
    }

    

    // now solve for each component, and if it works for all then true else impossible
    // if deg(x)==1, then the edge has to be incoming
    // for(auto &x: deg) cout << x << " ";
    // cout << endl;
    // visited.clear(); visited.resize(n);
    
    /*for(auto &x: deg) cout << x << " "; 
    cout << endl;*/
    for(auto &x: pos) {
        if(x) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for(auto &x: sol) cout << x.first+1 << " " << x.second+1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}

/*
bool cstm(int n1, int n2) {
    return deg[n1]<deg[n2];
}

for(int i=0; i<n; i++) {
        deg[i] = edges[i].size();
        if(!visited[i]) {
            components.push_back({});
            dfs(i);
            //sort(all(components.back()));
            int tmp = 0;
            for(auto &x: components.back()) tmp += edges[x].size();
            if(tmp%4==2) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    for(auto &x: components) {
        sort(all(x), cstm);
        
    }

*/

/*
for(int i=0; i<x.size(); i++) {
            visited[x[i]] = true;
            if(deg[x[i]]>1) {
                bool tmp = (deg[x[i]]+1)%2;
                for(auto &y: edges[x[i]]) {
                    if(!visited[y] and deg[y]>0) {
                        if(!tmp) tmp = true;
                        else {
                            deg[y]--;
                            sol[x[i]].push_back(y);
                            deg[x[i]]--;
                        }
                    }
                }
            }
            if(deg[x[i]]==0) continue;
            if(deg[x[i]]==1) {
                deg[x[i]]--;
                for(auto &y: edges[x[i]]) {
                    if(!visited[y] and deg[y]>0) {
                        deg[y]--;
                        if(sol[x[i]].size()%2==1) sol[x[i]].push_back(y);
                        else sol[y].push_back(x[i]);
                    }
                }
            }
        }
*/