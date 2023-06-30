#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll a, s; cin >> a >> s;
    vector<ll> b;
    bool possible = true;
    while(s) {
        ll t1 = a%10, t2 = s%10;
        a/=10; s/=10;
        if(t2>=t1) b.push_back(t2-t1);
        else {
            if(s%10 != 1) {
                possible = false;
                break;
            }
            else b.push_back(10+t2-t1);
            s/=10;
        }
        if(s==0 and a!=0) possible = false;
    }
    if(!possible) cout << -1 << endl;
    else {
        int temp = true;
        for(int i=b.size()-1; i>=0; i--) {
            if(b[i] != 0) temp = false;
            if(temp and b[i] == 0) continue;
            cout << b[i];
        }
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