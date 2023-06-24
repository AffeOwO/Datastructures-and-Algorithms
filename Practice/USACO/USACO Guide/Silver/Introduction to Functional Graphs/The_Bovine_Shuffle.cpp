#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int sol = 0;
vector<int> edges;
vector<bool> visited;
set<int> temp;

void dfs(int node) {
    //cout << sol << " " << node << endl;
    if(visited[node]) {
        if(temp.count(node)) {
            int cur = node, length = 1;
            while(edges[node] != cur) {
                node = edges[node];
                length++;
            }
            sol += length;
        }
        temp.clear();
        return;
    }
    visited[node] = true;
    temp.insert(node);
    dfs(edges[node]);
}

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    edges.resize(n);
    for(auto &x: edges) {
        int cur; fin >> cur;
        x = cur-1;
    }
    // sol = sum of lengths of cycles
    visited.resize(n);

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    fout << sol << endl;
}