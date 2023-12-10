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

    ll h, w; cin >> h >> w;   
    // w x h matrix
    vector<vector<ll>> A(h, vector<ll>(w));
    vector<vector<ll>> B = A;
    // map<ll, ll> a_cnt, b_cnt;
    vector<vector<ll>> rows_a, rows_b, columns_a, columns_b;
    for(auto &x: A) {
        rows_a.push_back({});
        for(auto &y: x) {
            cin >> y;
            // a_cnt[y]++;
            rows_a.back().push_back(y);
        }
        sort(all(rows_a.back()));
    }
    for(auto &x: B) {
        rows_b.push_back({});
        for(auto &y: x) {
            cin >> y;
            // b_cnt[y]++;
            rows_b.back().push_back(y);
        }
        sort(all(rows_b.back()));
    }
    for(ll j=0; j<w; j++) {
        columns_a.push_back({}); columns_b.push_back({});
        for(ll i=0; i<h; i++) {
            columns_a.back().push_back(A[i][j]);
            columns_b.back().push_back(B[i][j]);
        }
        sort(all(columns_a.back())); sort(all(columns_b.back()));
    }

    vector<vector<ll>> trows_a = rows_a, trows_b = rows_b, tcolumns_a = columns_a, tcolumns_b = columns_b;
    sort(all(rows_a)); sort(all(rows_b));
    sort(all(columns_a)); sort(all(columns_b));
    

    if(rows_a!=rows_b or columns_a != columns_b) cout << -1 << endl;
    else {
        ll sol = 0;
        // cells diagonal to each otehr can tbe in the same row/colúmn
        // first column, second row = first row, second column (commutative
        for(ll i=0; i<h; i++) {
            for(ll j=i; j<h; j++) {
                if(trows_a[j]==trows_b[i]) {
                    sol += (j-i);
                    for(ll k=j; k>i; k--) trows_a[k] = trows_a[k-1];
                    trows_a[i] = trows_b[i]; 
                    break;
                } 
            }
        }
        for(ll i=0; i<w; i++) {
            for(ll j=i; j<w; j++) {
                if(tcolumns_a[j]==tcolumns_b[i]) {
                    sol += (j-i);
                    for(ll k=j; k>i; k--) tcolumns_a[k] = tcolumns_a[k-1];
                    tcolumns_a[i] = tcolumns_b[i];
                    break;
                }
            }
        }
        cout << sol << endl;
    }
}