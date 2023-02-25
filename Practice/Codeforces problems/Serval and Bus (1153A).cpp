#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t; cin >> n >> t;
    pair<int, int> idk={999999999, -1};
    for(int i=0; i<n; ++i) {
        int s, d; cin >> s >> d;
        while(s<t) {
            s+=d;
        }
        idk = min(idk, pair<int, int> {s, i});
    }
    //cout << idk.second+1 << endl;
}