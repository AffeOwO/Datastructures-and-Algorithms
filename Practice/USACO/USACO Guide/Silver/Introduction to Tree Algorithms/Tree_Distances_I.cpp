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

int n;
vector<vector<int>> edges1;
vector<int> toLeaf1, par1;
vector<vector<pair<int, int>>> idk1;

void dfs1(int node, int par) {
    par1[node] = par;
    for(auto &x: edges1[node]) {
        if(x!=par) {
            dfs1(x, node);
            toLeaf1[node] = max(toLeaf1[node], toLeaf1[x]+1);
        }
    }
}

void bruh1(int node) {
    if(idk1[par1[node]][0].second==node) idk1[node].push_back({idk1[par1[node]][1].first+1, par1[node]});
    else idk1[node].push_back({idk1[par1[node]][0].first+1, par1[node]});
    for(auto &x: edges1[node]) {
        if(x!=par1[node]) idk1[node].push_back({toLeaf1[x]+1, x});
    }
    sort(all(idk1[node]), greater<pair<int, int>>());
    for(auto &x: edges1[node]) {
        if(x!=par1[node]) bruh1(x);
    }
}

void solve() {
    cin >> n;

	if(n==1) {
		cout << 0 << endl;
		return;
	}

    edges1.resize(n);
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges1[a].push_back(b);
        edges1[b].push_back(a);
    }
    toLeaf1.resize(n);
    par1.resize(n);
    
    dfs1(0, 0);

    idk1.resize(n);
    for(auto &x: edges1[0]) idk1[0].push_back({toLeaf1[x]+1, x});
    sort(all(idk1[0]), greater<pair<int, int>>());
    for(auto &x: edges1[0]) bruh1(x);

	for(auto &x: idk1) cout << x[0].first << " ";
	cout << endl; 
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	solve();
}