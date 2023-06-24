#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll n, t;
vector<ll> machines;

bool check(ll val) {
    ll produced = 0;
    for(auto &x: machines) produced += val/x;
    return produced>=t;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll mini = 1e9;
    cin >> n >> t;
    machines.resize(n);
    for(auto &x: machines) {
        cin >> x;
        mini = min(x, mini);
    }

    ll left = 0, right =  t*mini, sol = 0;
    while(left<=right) {
        ll mid = (left+right)/2;
        if(check(mid)) {
            sol = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << sol << endl;
}