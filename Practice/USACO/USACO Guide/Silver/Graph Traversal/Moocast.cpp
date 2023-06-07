#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges; // directed graph
int cur = 0, sol = 0;
vector<bool> visited;

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    cur++;
    for(auto &x: edges[node]) dfs(x);
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    edges.resize(n);
    vector<pair<pair<int, int>, int>> cows(n); // {x, y}, power of walki-talkie
    for(auto &x: cows) fin >> x.first.first >> x.first.second >> x.second;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(pow(cows[i].second, 2) >= pow(cows[i].first.first-cows[j].first.first, 2) + pow(cows[i].first.second-cows[j].first.second, 2)) {
                edges[i].push_back(j);
            }
        }
    }
    // find longest path
    for(int i=0; i<n; i++) {
        cur = 0;
        visited.resize(n);
        dfs(i);
        visited.clear();
        sol = max(cur, sol);
    }
    fout << sol << endl;
}