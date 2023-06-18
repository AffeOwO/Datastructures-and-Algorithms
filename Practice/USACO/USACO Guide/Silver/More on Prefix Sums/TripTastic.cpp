#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, m; ll k; cin >> n >> m >> k;  // k students + 1 mentor
    vector<vector<ll>> matrix(n+1, vector<ll> (m+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> matrix[i][j];
            matrix[i][j] += (matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1]);
        }
    }
    if(matrix[n][m] <= k) cout << -1 << endl;
    else {
        int sol = max(n, m)+1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int cur = sol;
                int l=0, r=sol;
                while(l<=r) {
                    int mid = (l+r)/2;
                    ll val = matrix[min(n, i+mid)][min(m, j+mid)] - matrix[min(n, i+mid)][max(0, j-mid-1)] - matrix[max(0, i-mid-1)][min(m, j+mid)] + matrix[max(0, i-mid-1)][max(0, j-mid-1)]; // fix
                    if(val>k)  {
                        // >k because 1mentor
                        cur = mid;
                        r = mid-1;
                    } 
                    else l = mid+1;
                }
                sol = min(sol, cur);
            }
        }
        cout << sol << endl;
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