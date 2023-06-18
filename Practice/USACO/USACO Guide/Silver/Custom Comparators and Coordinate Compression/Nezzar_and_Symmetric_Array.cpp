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
    vector<ll> abs_dif(2*n);
    for(auto &x: abs_dif) cin >> x;
    // array a is symmetric if for each a[i], there is an a[j] such that a[i] = -a[j]
    // array is of length 2n -> no 0
    // d[i] = 2*(...) -> no odd numbers and every number has to appear twice
    sort(all(abs_dif));
    for(int i=0; i<2*n; i+=2) {
        if(abs_dif[i] != abs_dif[i+1] or abs_dif[i]%2 or (i!=0 and abs_dif[i-2] == abs_dif[i])) {
            cout << "NO" << endl;
            return;
        }
    }
    ll rem = 0;
    for(ll i=2*(n-1); i>=0; i-=2) {
        if((abs_dif[i]-rem)%(i+2) or rem >= abs_dif[i]) {
            cout << "NO" << endl;
            return;
        }
        //cout << rem << " " << i << endl;
        rem += 2*((abs_dif[i]-rem)/(i+2));
    }
    cout << "YES" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}