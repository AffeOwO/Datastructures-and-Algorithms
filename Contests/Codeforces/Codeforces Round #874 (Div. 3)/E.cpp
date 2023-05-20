#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> perm(n);
    for(auto &x: perm) cin >> x;

    if(perm[0] != n) {
        // the index where n is, the suffix starts
        // the prefix end when the element is bigger than the first prefix element
        bool suf = false;
        int suf_ind;
        for(int i=0; i<n; i++) {
            if(perm[i] == n) {
                suf = true;
                suf_ind = i;    
            }
            if(suf) cout << perm[i] << " "; 
        }
        bool pref = false;
        int pref_ind;
        for(int i=0; i<n; i++) {
            if(perm[i] > perm[0] or (perm[0]==n-1 and perm[i]>perm[1] and i>1)) {
                pref = true;
                pref_ind = i;    
            }
            if(pref) {
                // reverse order
                for(int j=suf_ind-1; j>=i; j--) cout << perm[j] << " "; 
                break;
            }
        }
        for(int i=0; i<pref_ind; i++) cout << perm[i] << " ";
        cout << endl;
        return;
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