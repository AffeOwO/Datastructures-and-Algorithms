#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<pair<int, int>>> edges;
vector<bool> visited;
int mid, temp;

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    temp--;
    for(auto &x: edges[node]) {
        if(x.second<=mid) dfs(x.first);
    }
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    // binary search
    vector<pair<int, int>> coords(n);
    for(auto &x: coords) fin >> x.first >> x.second;
    // distance between two cows is ▲x² + ▲y²
    edges.resize(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            edges[i].push_back(make_pair(j, pow(coords[i].first-coords[j].first, 2)+pow(coords[i].second-coords[j].second, 2)));
        }
    }

    int left = 0, right = 1250000000;
    int sol = 0;
    while(left<=right) {
        mid = right - (right-left)/2;
        visited.resize(n);
        temp = n;
        dfs(0);
        if(temp==0) {
            sol = mid;
            right = mid-1;
        }
        else left = mid+1;
        visited.clear();
    }
    fout << sol << endl;
}