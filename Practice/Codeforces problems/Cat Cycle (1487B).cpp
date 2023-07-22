#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, k; cin >> n >> k;
    // 2 cats and n napping spots
    // cat A: (cur--) % n (start n); cat B: (cur++) % n (start 1)
    // if cur-- == cur++, then cur-- and cur+=2
    // where will cat B be at hour x
    int temp = n/2;
    cout << (k-1+(n%2)*(k-1)/temp)%n+1 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}