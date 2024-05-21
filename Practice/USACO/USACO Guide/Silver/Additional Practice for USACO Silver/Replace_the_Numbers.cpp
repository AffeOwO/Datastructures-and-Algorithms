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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> q;
    vector<int> t(q), x(q), y(q, -1);
    for(int i=0; i<q; i++) {
        cin >> t[i] >> x[i];
        if(t[i]==2) cin >> y[i];
    }
    vector<int> p(5*100001);
    for(int i=0; i<5*100001; i++) {
        p[i] = i;
    }

    vector<int> sol;
    for(int i=q-1; i>=0; i--) {
        if(t[i]==1) {
            sol.push_back(p[x[i]]);
        }
        else {
            p[x[i]] = p[y[i]];
        }
    }
    for(int i=sol.size()-1; i>=0; i--) cout << sol[i] << " ";
    cout << endl;
}