#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<bool> appeared(n);
    vector<int> sol;
    for(int i=0; i<3*n; i++) {
        int cur; cin >> cur;
        cur--;
        if(!appeared[cur]) appeared[cur] = true;
        else {
            sol.push_back(cur);
            appeared[cur] = false;
        }
    }
    for(auto &x: sol) cout << x+1 << " ";
    cout << endl;
}