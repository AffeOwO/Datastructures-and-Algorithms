#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    // 1 is in S; ax and b+x is in S for all x in S
    if(a==1) {
        if((n-1)%b==0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        ll temp = 1;
        bool sol = false;
        while(temp<=n) {
            if(temp%b==n%b) {
                sol = true;
                break;
            }
            temp*=a;
        }
        sol ? cout << "Yes" : cout << "No";
        cout << endl;
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