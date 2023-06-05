#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<int> colored; // 0 = none, 1 = blue, 2 = red
map<int, vector<int>> nodes;
bool possible = true;

void dfs(int node, int pref) {
    if(colored[node] != 0 or !possible) return;
    colored[node] = 2-pref;
    for(auto &x: nodes[node]) {
        if(colored[x] == colored[node]) {
            possible = false;
            return;
        }
        dfs(x, (pref+1)%2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // graph coloring with 2 colors, check if possible
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    colored.resize(n);
    for(int i=0; i<n; i++) {
        if(colored[i] == 0) dfs(i, 1);
    }

    if(!possible) cout << "IMPOSSIBLE" << endl;
    else {
        for(auto &x: colored) cout << x << " ";
        cout << endl;
    }
}