#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n; cin >> n; // n friends
    // slices:time
    // 6:15; 8:20; 10:25
    // min time required to make at least n slices
    // 2 slices = 5min
    if(n<=6) cout << 15 << endl;
    else if(n<=8) cout << 20 << endl;
    else if(n<=10) cout << 25 << endl;
    else {
        if(n%2) cout << (n+1)/2*5 << endl;
        else cout << n/2*5 << endl;
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