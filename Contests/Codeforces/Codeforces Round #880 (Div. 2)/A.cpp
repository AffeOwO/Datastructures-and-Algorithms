#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    map<int, int> robots;
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        robots[cur]++;
    }
    if(!robots.count(0)) cout << "NO" << endl;
    else {
        int temp = robots[0];
        for(auto &x: robots) {
            if(x.second>temp or (x.first != 0 and !robots.count(x.first-1))) {
                cout << "NO" << endl;
                return;
            }
            temp = x.second;
        }
        cout << "YES" << endl;
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