#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
int sol = 0;

void dfs(int node, int prev) {
    int cur = 0, idk = edges[node].size();
    if(prev == -1) idk++;
    int temp = 1, addi = 0;
    while(temp<idk) {
        addi++;
        temp *= 2;
    }
    sol += addi;
    for(auto &x: edges[node]) {
        if(x != prev) {
            dfs(x, node);
            sol++;
        }
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    edges.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    cout << sol << endl;
}