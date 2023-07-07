#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    vector<string> idk(3);
    for(auto &x: idk) cin >> x;
    
    if(idk[0][0] == idk[1][1] and idk[1][1] == idk[2][2] and idk[0][0] != '.') cout << idk[0][0] << endl;
    else if(idk[0][2] == idk[1][1] and idk[1][1] == idk[2][0] and idk[1][1] != '.') cout << idk[1][1] << endl;
    else {
        for(int i=0; i<3; i++) {
            if(idk[0][i] == idk[1][i] and idk[0][i] == idk[2][i] and idk[0][i] != '.') {
                cout << idk[0][i] << endl;
                return;
            }
            if(idk[i][0] == idk[i][1] and idk[i][0] == idk[i][2] and idk[i][0] != '.') {
                cout << idk[i][0] << endl;
                return;
            }
        }

        cout << "DRAW" << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}