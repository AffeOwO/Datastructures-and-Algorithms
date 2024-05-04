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

int n;

void solve() {
    // n % 4 in {0, 3}

    // how many ways are there to pick distinct numbers (<= n) such that their sum is n(n+1)/4
    vector<ll> sol(n*(n+1)/4+1);
    sol[0] = 1;

    for(ll i=1; i<n; i++) {
        for(ll j=sol.size(); j>=0; j--) {
            if(j+i<(ll)sol.size()) sol[j+i] = (sol[j] + sol[j+i])%MOD;
        }
    }

    cout << sol.back() << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    if(n%4==1 or n%4==2) cout << 0 << endl;
    else solve();
}