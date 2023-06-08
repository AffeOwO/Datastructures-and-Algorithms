#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> edges;
vector<int> cycle_len;
int length;
queue<int> cur;
vector<bool> visited;

void find_length(int node) {
    cur.push(node);
    if(visited[node]) {
        length += cycle_len[node];
        return;
    }
    visited[node] = true;
    length++;
    find_length(edges[node][0]);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    // naive wont work
    edges.resize(n);
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        cur--;
        edges[i].push_back(cur);
    }
    cycle_len.resize(n);
    visited.resize(n);
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            length = 0;
            find_length(i);
            int dec = 1;
            while(!cur.empty()) {
                if(cur.front() == cur.back()) dec = 0;
                cycle_len[cur.front()] = length;
                length -= dec;
                cur.pop();
            }
        }
    }
    for(auto &x: cycle_len) cout << x << " ";
    cout << endl;
}