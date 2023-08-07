#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    int s = 0;
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        s += cur;
    }
    if(s%2==0) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}