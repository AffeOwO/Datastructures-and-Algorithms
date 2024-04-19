#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, k; 

bool cstm(pair<ll, int> p1, pair<ll, int> p2) {
    for(int i=k-1; i>=0; i--) {
        // (x>>k)&1
        if(((p1.first>>i)&1) == ((p2.first>>i)&1)) continue;
        return ((p1.first>>i)&1) < ((p2.first>>i)&1);
    }
    return 0;
}

void solve() {
    cin >> n >> k;
    // integers are called martian if they are non negative and <2^k
    // maximize (a[i] xor x)and(a[j] xor x); output (i, j, x)
    vector<pair<ll, int>> seq(n);
    for(int i=0; i<n; i++) {
        cin >> seq[i].first;
        seq[i].second = i;
    }
    // k bits per number -> < 2^k
    // if a[i] = b[i], then res[i] = 1 else res[i] = 0
    // find i, j such that (s[i] and s[j]) is maximized or (not s[i] and not s[j]))
    sort(all(seq), cstm);
    
    /*for(auto &x: seq) {
        for(int i=k-1; i>=0; i--) cout << ((x.first>>i)&1);
        cout << endl;
    }*/

    pair<ll, vector<ll>> sol = {-1, {0, 0, 0}};
    for(int i=0; i<n-1; i++) {
        ll tmpx = 0, tmpval = 0;
        for(int j=k-1; j>=0; j--) {
            if(((seq[i].first>>j)&1) == ((seq[i+1].first>>j)&1)) {
                tmpval += (1<<j);
                if(((seq[i].first>>j)&1)==0) tmpx += (1<<j);
            }
        }
        if(tmpval>sol.first) sol = {tmpval, {seq[i].second+1, seq[i+1].second+1, tmpx}};
    }

    for(auto &x: sol.second) cout << x << " ";
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}