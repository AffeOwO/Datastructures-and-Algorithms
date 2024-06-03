#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

void solve() {
    int n, f, k; cin >> n >> f >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int tmp = a[f-1];
    sort(all(a), greater<int>());
    pair<int, int> idk; idk.second = n;
    for(int i=0; i<n; i++) {
        if(i!=0 and a[i-1]!=tmp and a[i]==tmp) idk.first = i+1;
        if(i!=0 and a[i]!=tmp and a[i-1]==tmp) idk.second=i; 
    }
    if(idk.first<=k) {
        if(idk.second>k) cout << "MAYBE" << endl;
        else cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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