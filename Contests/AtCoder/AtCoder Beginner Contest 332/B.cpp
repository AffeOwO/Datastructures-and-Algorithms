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

    // g<m;
    ll k, g, m; cin >> k >> g >> m;   
    int glass = 0, mug = 0;
    while(k--) {
        if(glass==g) glass = 0;
        else if(mug==0) mug = m;
        else {
            if(g-glass>=mug) {
                glass += mug;
                mug = 0;
            }
            else {
                mug -= (g-glass);
                glass = g;
            }
        }
    }
    cout << glass << " " << mug << endl;
}