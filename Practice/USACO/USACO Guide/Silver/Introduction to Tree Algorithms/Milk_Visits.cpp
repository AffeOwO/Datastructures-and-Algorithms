#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
map<int, int> ind; // index of component it is in
vector<bool> visited;
string s;
int a, b;
char c;

void dfs(int node, int comp, char idk) {
    if(visited[node] or s[node] != idk) return;
    visited[node] = true;
    ind[node] = comp;
    for(auto &x: edges[node]) dfs(x, comp, idk);
}

int main() {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; fin >> n >> m;
    fin >> s;
    edges.resize(n);
    for(int i=0; i<n-1; i++) {
        int x, y; fin >> x >> y;
        x--; y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // precompute components
    visited.resize(n);
    int cur = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, cur, s[i]);
            cur++;
        }
    }


    for(int i=0; i<m; i++) {
        fin >> a >> b >> c;
        a--; b--;
        if(s[a] == c or s[b] == c) fout << 1;
        else {
            if(ind[a] != ind[b]) fout << 1;
            else fout << 0;
        }
    }
    fout << endl;
}

/*
void dfs(int node, bool state) {
    if(visited[node]) return;
    visited[node] = true;
    if(s[node] == c) state = true;
    for(auto &x: edges[node]) dfs(x, state);
    if(node == b) {
        if(state) pos = true;
        return;
    }
}


for(int i=0; i<m; i++) {
        fin >> a >> b >> c;
        // go from farm a to b, if farm on path is c, then 1 else 0
        a--; b--;
        visited.resize(n);
        pos = false;

        dfs(a, false);

        if(pos) fout << 1;
        else fout << 0;
        visited.clear();
    }
    fout << endl;
*/