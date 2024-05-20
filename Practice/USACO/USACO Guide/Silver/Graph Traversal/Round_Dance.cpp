#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool pos = true;
int mini = 0, maxi = 0, cnt = 0, tmp = 0;
vector<set<int>> edges;
vector<bool> visited;
vector<int> neighbor;

void dfs_maxi(int node) {
    if(visited[node]) return;
    visited[node] = true;
    for(auto &x: edges[node]) dfs_maxi(x);
}

void dfs_mini(int node) {
    if(visited[node]) return;
    visited[node] = true;
    tmp++;
    if(edges[node].size()!=2) pos = false;
    for(auto &x: edges[node]) dfs_mini(x);
}

void solve() {
    int n; cin >> n;
    mini = 0; maxi = 0; cnt = 0;
    neighbor.resize(n);
    for(auto &x: neighbor) cin >> x;

    // each person only participates in one dance
    edges.resize(n); visited.resize(n);
    for(int i=0; i<n; i++) {
        edges[i].insert(neighbor[i]-1);
        edges[neighbor[i]-1].insert(i);
    }
    // max dances is amount of components

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            //cout << i << endl;
            maxi++;
            dfs_maxi(i);
        }
    }
    visited.clear(); visited.resize(n);
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            pos = true;
            tmp = 0;
            dfs_mini(i);
            if(pos) {
                cnt += tmp;
                mini++;
            }
        }
    }

    // cout << cnt << endl;
    if(cnt!=n) mini++;
    cout << mini << " " << maxi << endl;
    visited.clear(); edges.clear(); neighbor.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}