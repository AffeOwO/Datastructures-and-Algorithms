#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
bool sol = false;
pair<int, int> cur_lost;
vector<bool> visited;
int cnt;

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    cnt--;
    for(auto &x: edges[node]) {
        if((node == cur_lost.first and x == cur_lost.second) or (node == cur_lost.second and x == cur_lost.first)) continue;
        dfs(x);
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        int p, c; cin >> p >> c;
        if(p==0 and c==0) break;
        edges.resize(p);
        vector<pair<int, int>> connections(c);
        for(int i=0; i<c; i++) {
            int a, b; cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
            connections.push_back({a, b});
        }

        for(auto x: connections) {
            cur_lost = x;
            cnt = p;
            visited.clear();
            visited.resize(p);
            dfs(0);
            if(cnt != 0) sol = true;
        }

        if(sol) cout << "Yes" << endl; // someone couldnt be invited
        else cout << "No" << endl;

        sol = false;
        edges.clear();
    }
}