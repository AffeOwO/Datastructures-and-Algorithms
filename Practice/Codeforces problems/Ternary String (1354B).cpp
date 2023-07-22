#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int maxi(tuple<int, int, int> tup) {
    return max({get<0>(tup), get<1>(tup), get<2>(tup)});
}
int mini(tuple<int, int, int> tup) {
    return min({get<0>(tup), get<1>(tup), get<2>(tup)});
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    // each char of s is in {1, 2, 3}
    // find shortest substring such that 1, 2, 3 are in it
    // pointer?
    tuple<int, int, int> last = {-1, -1, -1};
    int sol = n+1;
    for(int i=0; i<n; i++) {
        switch(s[i]) {
            case '1':
                get<0>(last) = i;
                break;
            case '2':
                get<1>(last) = i;
                break;
            case '3':
                get<2>(last) = i;
                break;
        }
        if(mini(last) != -1) sol = min(sol, maxi(last) - mini(last));
    }
    if(sol == n+1) cout << 0 << endl;
    else cout << sol+1 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}