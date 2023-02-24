#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

ll new_num(ll n) {
    ll orig = n;
    ll smallest = 10, biggest = -1;
    while(n) {
        ll cur = n % 10;
        if(cur>biggest) {biggest = cur;}
        if(cur<smallest) {smallest = cur;}
        n /= 10;
    }
    return orig + biggest*smallest;
}

void solve() {
    ll a, k;
    cin >> a >> k;
    while(true) {
        if(k<=1) {
            cout << a << endl;
            return;
        }
        a = new_num(a);
        string str_a = to_string(a);
        for(auto x: str_a) {
            if(x=='0') {
                cout << a << endl;
                return;
            }
        }
        k -= 1;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }   
}