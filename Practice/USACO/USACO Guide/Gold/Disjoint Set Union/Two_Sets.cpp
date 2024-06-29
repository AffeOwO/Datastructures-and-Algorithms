#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

void solve() {
    int n, a, b; cin >> n >> a >> b;
    map<int, bool> visited;
    set<int> nodes;
    map<int, int> ind;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        nodes.insert(x);
        ind[x] = i;
        visited[x] = false;
    }
    map<int, vector<int>> edges;
    for(auto &x: nodes) {
        if(nodes.count(a-x)) edges[x].push_back(a-x);
        if(nodes.count(b-x)) edges[x].push_back(b-x);
    }

    vector<int> sol(n);

    for(auto &x: visited) {
        if(!x.second) {
            int l = 1, r = 0;
            

            if((l+r)%2==1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}