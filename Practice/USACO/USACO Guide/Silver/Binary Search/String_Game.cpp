#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

string t, p; 
int n;
vector<int> perm;

bool check(int cur) {
    int pnt = 0;
    vector<bool> temp(n);
    for(int i=0; i<cur; i++) temp[perm[i]-1] = true;
    for(int i=0; i<n; i++) {
        if(temp[i]) continue;
        if(t[i]==p[pnt]) {
            pnt++;
            if(pnt==p.size()) return true;
        }
    }
    //cout << pnt << " " << cur << endl;
    return false;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> p; // |p| < |t|
    n = t.size();
    perm.resize(n); // we only have to care abt the first |p| numbers
    for(auto &x: perm) cin >> x;

    int l=0, r=n, m, sol = 0;
    while(l<=r) {
        m = (l+r)/2;
        if(check(m)) {
            sol = m;
            l = m+1;
        }
        else r = m-1;
    }
    cout << sol << endl;
}