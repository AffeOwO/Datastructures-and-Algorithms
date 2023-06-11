#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<int> cows;
vector<vector<pair<int, int>>> edges; // .first = destination, .second = width
int to_v;
vector<bool> visited;
int mid; // wormholes >= m can be used

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second>p2.second;
}

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    if(cows[node] != node) to_v--;
    for(auto &x: edges[node]) {
        if(x.second<mid) break; // sort by x.second
        dfs(x.first);
    }
}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; fin >> n >> m; // n cows and m wormholes
    int wrong_pos = 0;
    int sn;
    cows.resize(n); // index is the node and the value is the cow currently at that node
    for(int i=0; i<n; i++) {
        int cur; fin >> cur; // cow i is at pos cur
        cur--;
        if(i!=cur) {
            wrong_pos++;
            sn = cur;
        }
        cows[cur] = i;
    }
    if(wrong_pos == 0) {
        fout << -1 << endl;
        return 0;
    }
    // the edges: edge e connects nodes a and b with cost d, binary search the min value of d
    int max_w = 0;
    edges.resize(n);
    for(int i=0; i<m; i++) {
        int a, b, w; fin >> a >> b >> w;
        if(w>max_w) max_w = w;
        a--; b--;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    for(auto &x: edges) sort(all(x), cmp);

    int l = 0, r = max_w+1;
    int sol;
    while(l<r-1) {
        mid = (l+r)/2;
        visited.resize(n);
        to_v = wrong_pos;
        dfs(sn);
        if(to_v == 0) {
            l = mid;
            sol = mid;
        }
        else r = mid;
        visited.clear();
    }
    to_v = wrong_pos;
    visited.resize(n);
    mid = sol+1;
    dfs(sn);
    if(to_v==0) fout << sol+1 << endl;
    else fout << sol << endl;
}