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
    
    int n, q; cin >> n >> q;
    vector<vector<int>> pref(n+1, vector<int>(30)); // 1e9 is 30 digits in binary
    for(int i=1; i<=n; i++) {
        int cur; cin >> cur;
        bitset<30> idk(cur);
        for(int j=0; j<30; j++) {
            pref[i][j] = pref[i-1][j];
            if(idk.test(j)) pref[i][j]++;;
        }
    }
    while(q--) {
        int a, b; cin >> a >> b; // pref[b]-pref[a-1]
        vector<int> idk = pref[b];
        for(int i=0; i<30; i++) idk[i] -= pref[a-1][i];
        int sol = 0;
        for(int i=0; i<30; i++) {
            if(idk[i]%2==1) sol += pow(2, i);
        }
        cout << sol << endl;
    }
}