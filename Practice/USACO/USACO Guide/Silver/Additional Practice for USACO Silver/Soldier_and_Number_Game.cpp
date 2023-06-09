#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<int> divisors(5e6+1), cache(5e6+1); // cache[i] is for i+1

void find_primes() {
    // bug: at 2.5e6 it inserts 0 into the vector
    for(int i=2; i<=5e6; i++) {
        if(divisors[i] == 0) {
            for(int j=i; j<=5e6; j+=i) divisors[j] = i;
        }
    }
}

void build_cache() {
    for(int i=2; i<=5e6; i++) cache[i] = cache[i/divisors[i]]+1;
    for(int i=2; i<=5e6; i++) cache[i] = cache[i] + cache[i-1];
}

void solve() {
    int a, b; cin >> a >> b;
    cout << cache[a] - cache[b] << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    find_primes();
    build_cache();
    int t; cin >> t;
    while(t--) solve();
}