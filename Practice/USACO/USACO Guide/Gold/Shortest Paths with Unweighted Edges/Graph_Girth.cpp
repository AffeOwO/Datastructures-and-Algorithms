#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<int> prev(n); 
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int sol = 2501;

    for(int i=0; i<n; i++) {
        // check if cycle goes through node i
        vector<int> dist(n);
        vector<bool> visited(n); visited[i] = true;
        queue<int> q; q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            vector<bool> disty(n);
            for(auto &x: edges[cur]) {
                if(visited[x]) {
                    if(disty[dist[x]]) sol = min(sol, 2*(dist[x]+1));
                    disty[dist[x]] = true;
                    //if(i==1) cout << dist[x] << " " << dist[cur] << endl;
                    if(dist[x] == dist[cur]) sol = min(sol, 2*dist[x]+1);
                    continue;
                }
                visited[x] = true;
                dist[x] = dist[cur]+1;
                q.push(x);
            }
        }
    }
    if(sol==2501) cout << -1 << endl;
    else cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}