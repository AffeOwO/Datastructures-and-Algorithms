#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll sol = 0;
vector<pair<int, ll>> cows; // edges
vector<bool> visited;
vector<vector<int>> edges; // for component search
vector<int> components; // one node from each component

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    components.back() = node;
    for(auto &x: edges[node]) dfs(x);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n; // n cows
    cows.resize(n); // cow p[i] visited cow a[p[i]] where p is some permutation of (0, 1, ..., n)
    edges.resize(n);
    for(int i=0; i<n; i++) {
        cin >> cows[i].first >> cows[i].second;
        sol += cows[i].second;
        cows[i].first--;
        edges[i].push_back(cows[i].first);
        edges[cows[i].first].push_back(i);
    }
    // find longest path
    // optimise each component seperatly
    visited.resize(n);
    // find components
    // do i have to know all nodes from each components?
    // if cycle, then start at cow where the ingoing edge is minimized
    // no self-loops
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            components.push_back(0);
            dfs(i);
        }
    }

    for(auto &x: components) {
        // every weigth is going to be added except one in each component (lowest in each cycle)
        // -> find cycle in each component and substract lowest weigth in it from sol
        // floyds algorithm
        int slow = x, fast = cows[x].first;
        while(slow != fast) {
            slow = cows[slow].first;
            fast = cows[cows[fast].first].first;
        }
        if(cows[slow].first == slow) continue;
        ll smallest = 1e9;
        while(cows[slow].first != fast) {
            smallest = min(smallest, cows[slow].second);
            slow = cows[slow].first;
        }
        smallest = min(smallest, cows[slow].second);
        sol -= smallest;
    }

    cout << sol << endl;
}