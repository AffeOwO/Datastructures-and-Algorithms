#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n;
vector<vector<int>> edges;
vector<bool> visited;
map<int, double> journeys; // .first = length, .second = probability -> E(x) = sum(length*probability)

void dfs(int node, int length, double cur_prob) {
    if(visited[node]) return;
    visited[node] = true;
    if(edges[node].size() == 1 and visited[edges[node][0]]) {
        // add to journeys
        journeys[length] += cur_prob;
    }
    else {
        if(node == 0) {
            for(auto &x: edges[node]) dfs(x, length+1, cur_prob/edges[node].size());
        }
        else {
            for(auto &x: edges[node]) dfs(x, length+1, cur_prob/(edges[node].size()-1));
        }
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    if(n==1) {
        cout << 0 << endl;
        return 0;
    }
    edges.resize(n);
    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    visited.resize(n);
    dfs(0, 0, 1);
    
    double sol = 0;
    for(auto &x: journeys) {
        sol += x.second*x.first; 
    }
    cout << setprecision(10) << sol << endl;
}