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
    vector<pair<int, int>> dominos(n);
    pair<int, int> idk; // .first = lower, .second = upper
    for(int i=0; i<n; i++) {
        int t1, t2; cin >> t1 >> t2;
        dominos[i] = {t1&1, t2&1};
        idk = {idk.first^dominos[i].first, idk.second^dominos[i].second};
    }
    if(idk.first == 0 and idk.second == 0) cout << 0 << endl;
    else if((idk.first == 1 and idk.second == 0) or (idk.first == 0 and idk.second == 1)) cout << -1 << endl;
    else {
        bool possible = false;
        for(auto &x: dominos) {
            if((x.first == 1 and x.second == 0) or (x.first == 0 and x.second == 1)) possible = true;
        }

        if(possible) cout << 1 << endl;
        else cout << -1 << endl;
    }
}