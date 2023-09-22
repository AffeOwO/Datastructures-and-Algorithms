#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> parents(n), edges(n);
    for(auto &x: parents) cin >> x;
    vector<vector<int>> sol;

    if(n==1) {
        cout << 1 << endl << 1 << endl << 1 << endl << endl;
        return;
    }

    for(int i=0; i<n; i++) {
        edges[parents[i]-1]++;
    }

    vector<int> leafs;
    for(int i=0; i<n; i++) {
        if(edges[i] == 0) leafs.push_back(i+1);
    }
    vector<bool> visited(n);
    for(auto &x: leafs) {
        sol.push_back({x});
        visited[x-1] = true;
        int cur = x;
        while(!visited[parents[cur-1]-1]) {
            //cout << cur << " " << parents[cur-1] << " " << visited[cur-1] << " " << visited[parents[cur-1]] << endl;
            cur = parents[cur-1];
            visited[cur-1] = true;
            sol.back().push_back(cur);
        }
    }

    cout << sol.size() << endl; // = amount of leafs
    for(auto &x: sol) {
        cout << x.size() << endl;
        for(int i = x.size()-1; i>=0; i--) cout << x[i] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}