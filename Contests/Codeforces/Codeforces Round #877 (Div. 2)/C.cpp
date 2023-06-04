#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool is_prime(int x) {
    for(int i=2; i<=sqrt(x); i++) {
        if(x%i==0) return false;
    }
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    if(m%2==0 or !is_prime(m)) {
        for(int i=0; i<n; i++) {
            for(int j=1; j<=m; j++) {
                cout << i*m+j << " ";
            }
            cout << endl;
        }
    }
    else if(n%2==0 or !is_prime(n)) {
        for(int i=1; i<=n; i++) {
            for(int j=0; j<m; j++) {
                cout << i+j*n << " ";
            }
            cout << endl;
        }
    }
    else {
        // n%2=1 and m%2=1 and both are prime
        int cnt = 0;
        for(int i=0; i<n; i++) {
            vector<int> cur(m);
            for(int j=1; j<=m; j++) {
                cur[j-1] = j+i*m;
            }
            for(int j=0; j<m; j++) cout << cur[(j+cnt)%m] << " ";
            cout << endl;
            cnt++;
        }
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