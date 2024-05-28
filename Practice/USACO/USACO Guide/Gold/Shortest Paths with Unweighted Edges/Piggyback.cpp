#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;

int main() {
    ifstream fin("piggyback.in");
    ofstream fout("piggyback.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll b, e, p, n, m; fin >> b >> e >> p >> n >> m;
    // bessie starts in field 1 and elsie starts in farm 2 barn is in farm n
    edges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; fin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // if p>=b+e -> sum of shortest paths
    // else min(sum of shortest paths, piggyback + shortest path to meeting)

    vector<ll> dist1(n), dist2(n), dist3(n);
    vector<bool> visited(n); visited[0] = true;
    queue<ll> q; q.push(0);
    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        for(auto &x: edges[cur]) {
            if(visited[x]) continue;
            visited[x] = true;
            dist1[x] = dist1[cur]+1;
            q.push(x);
        }
    }
    visited.clear(); visited.resize(n);
    visited[1] = true;
    q.push(1);
    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        for(auto &x: edges[cur]) {
            if(visited[x]) continue;
            visited[x] = true;
            dist2[x] = dist2[cur]+1;
            q.push(x);
        }
    }
    visited.clear(); visited.resize(n);
    visited[n-1] = true;
    q.push(n-1);
    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        for(auto &x: edges[cur]) {
            if(visited[x]) continue;
            visited[x] = true;
            dist3[x] = dist3[cur]+1;
            q.push(x);
        }
    }
    ll sol = dist1[n-1]*b + dist2[n-1]*e;
    for(int i=0; i<n-1; i++) sol = min(sol, dist1[i]*b+dist2[i]*e+dist3[i]*p);
    fout << sol << endl;
}