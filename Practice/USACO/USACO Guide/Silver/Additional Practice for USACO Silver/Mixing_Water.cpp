#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int h, c, t;

void solve() {
    cin >> h >> c >> t; // h = hot water temp; c = cold water temp, c<h; t = temp to reach
    // temp in barrel is average of poured in
    // for even amount, 2 is the only thing which makes sense (4, 6, 8 will have the same value as 2); for even amount, it has to = t
    if(h==t) cout << 1 << endl;
    else if(t==c or (h+c)/2>=t) cout << 2 << endl;
    else {
        int a = h - t;
		int b = 2 * t - c - h;
		int k = 2 * (a / b) + 1;
		ll val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
		ll val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));
        if(val1*(k+2)<=val2*k) cout << k << endl;
        else cout << k+2 << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc; cin >> tc;
    while(tc--) solve();
}