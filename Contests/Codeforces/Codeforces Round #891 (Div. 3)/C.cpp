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
    map<int, int> cnt;
    for(int i=0; i<n*(n-1)/2; i++) {
        int cur; cin >> cur;
        cnt[cur]++;
    }
    // biggest number can be any number
    int temp = n-1;

    for(auto &x: cnt) {
        while(x.second) {
            x.second -= temp;
            temp--;
            cout << x.first << " ";
        }
    }

    cout << 1000000000 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}