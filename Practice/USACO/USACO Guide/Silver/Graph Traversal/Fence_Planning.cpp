#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<pair<int, int>> cows;
vector<vector<int>> edges;
vector<bool> visited;
int minx, miny, maxx, maxy;

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    // check for minima and maxima
    pair<int, int> cur = cows[node];
    if(cur.first>maxx) maxx = cur.first;
    if(cur.first<minx) minx = cur.first;
    if(cur.second>maxy) maxy = cur.second;
    if(cur.second<miny) miny = cur.second;
    for(auto &x: edges[node]) dfs(x);
}

int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; fin >> n >> m; // n=cows; 
    // find all components and choose the one with smallest perimeter if fenced
    cows.resize(n);
    for(auto &x: cows) fin >> x.first >> x.second;
    edges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; fin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int sol = 1e9;
    visited.resize(n);
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            // do stuff
            minx = 1e9; maxx = -1; miny = 1e9; maxy = -1;
            dfs(i);
            //cout << maxx << " " << maxy << " " << minx << " " << miny << endl;
            int perimeter = 2*(maxx-minx + maxy-miny);
            sol = min(sol, perimeter);
        }
    }
    fout << sol << endl;
}