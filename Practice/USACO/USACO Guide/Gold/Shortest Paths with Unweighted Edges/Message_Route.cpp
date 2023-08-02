#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream cin("temp.in");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    // shortest path from node 0 to n-1
    vector<vector<int>> edges(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // change in a way such that routes are being saved too
    vector<int> dist(n, -1); dist[0] = 1;
    vector<int> par(n); par[0] = -1;
    vector<bool> visited(n); visited[0] = true;
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x: edges[cur]) {
            if(visited[x]) continue;
            visited[x] = true;
            dist[x] = dist[cur] + 1;
            par[x] = cur;
            q.push(x);
        }
    }

    if(dist[n-1] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        cout << dist[n-1] << endl;
        vector<int> route = {n};
        int cur = n-1;
        while(par[cur] != -1) {
            route.push_back(par[cur]+1);
            cur = par[cur];
        }
        for(int i=route.size()-1; i>=0; i--) cout << route[i] << " ";
        cout << endl;
    }
}