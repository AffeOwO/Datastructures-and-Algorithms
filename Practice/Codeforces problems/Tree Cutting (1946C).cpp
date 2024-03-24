#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, k, temp; 
vector<vector<int>> edges;
vector<int> chi;

void dfs(int node, int par, int idk) {
    chi[node] = 1;
    for(auto &x: edges[node]) {
        if(x!=par) {
            dfs(x, node, idk);
            chi[node] += chi[x];
        }
    }
    if(chi[node]>=idk) {
        temp++;
        chi[node] = 0;
    }
}

bool pos(int mini) {
    // check if it is possible to get k+1 connected components such that each of them has at least mini nodes in it
    temp = 0;
    dfs(1, 0, mini);
    return temp-1>=k;
}

void solve() {
    cin >> n >> k;
    edges.resize(n+1); chi.resize(n+1);
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // find max x such that you can remove k edges and every remaining connected component has at least x nodes
    // k+1 connected components
    // for(auto &x: children) cout << x << " ";


    int left = 1, right = n;
    while(left<right) {
        int mid = (left+right+1)/2;
        
        if(pos(mid)) left = mid;
        else right = mid-1;
    }
    cout << left << endl;
    edges.clear(); chi.clear();
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}