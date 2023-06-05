#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<bool> visited, closed;
vector<vector<int>> edges;
int cnt;

void dfs(int node) {
    if(visited[node]) return;
    cnt--;
    visited[node] = true;
    for(auto &x: edges[node]) dfs(x);
}

int main() {
    ifstream fin("closing.in");
    ofstream fout("closing.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; fin >> n >> m;
    closed.resize(n);
    edges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b; fin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int smallest = 0;
    for(int i=0; i<n; i++) {
        cnt = n-i;
        visited = closed;
        
        dfs(smallest);
        if(cnt == 0) fout << "YES" << endl;
        else fout << "NO" << endl;

        int temp; fin >> temp;
        temp--;
        closed[temp] = true;
        if(temp==smallest) {
            for(int i=0; i<n; i++) {
                if(!closed[i]) {
                    smallest = i;
                    break;
                }
            }
        }
    }
}