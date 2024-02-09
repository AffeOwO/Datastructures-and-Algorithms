#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int x, n; cin >> x >> n;
    // find n natural numbers such that their sum is x and their gcd is the maximum possible
    // the gcd divides x
    vector<int> divs;

    for(int i=1; i<=sqrt(x); i++) {
        if(x%i==0) {
            divs.push_back(i);
            if(i*i!=x) divs.push_back(x/i); 
        }
    }
    sort(all(divs), greater<int>());
    
    for(auto &y: divs) {
        // test if possible
        if(x/y>=n) {
            cout << y << endl;
            return;
        }
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