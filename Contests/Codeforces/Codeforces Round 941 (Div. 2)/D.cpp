#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, k; cin >> n >> k;
    // length at most 25
    // for all i<=n i!=k, there must exist a subsequence of seq with sum i
    // if x in seq, then k-x cant be in seq
    // -> x is in the sum of k-x assuming x<k-x

    // if k==1, then just 2^c, c>0
    if(k==1) {
        cout << 25 << endl;
        for(int i=1; i<=25; i++) cout << (1<<i) << " ";
        cout << endl;
    }
    else {
        int smallest = 2e9, biggest;
        for(int i=0; i<25; i++) {
            if(((k>>i)&1)) {
                smallest = min(smallest, i);
                biggest = i;
            }
        }
        // 20 powers of 2
        cout << 25 << endl;
        for(int i=0; i<20; i++) {
            if(i!=biggest) cout << (1<<i) << " ";
        }
        cout << (1<<biggest)-(1<<smallest) << " ";
        
        cout << endl;
        // 6 nums left
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}