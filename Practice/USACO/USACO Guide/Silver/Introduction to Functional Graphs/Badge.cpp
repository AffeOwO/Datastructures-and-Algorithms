#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> nodes(n);
    for(auto &x: nodes) cin >> x;

    for(int i=1; i<=n; i++) {
        set<int> visited;
        int cur = i;
        while(!visited.count(cur)) {
            visited.insert(cur);
            cur = nodes[cur-1];
        }
        cout << cur << " ";
    }
    cout << endl;
}