#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n;
vector<int> colors;
map<int, vector<int>> occ; // .first = color, .second contains indices where color is

int idk(int idx, int length) {
    int temp = length;
    for(int i=idx; i<n; i++) {
        for(auto &x: occ[colors[i]]) {
            if(x<=i) continue;
            length = max(length, idk(x+1, temp+x-i+1));
            //cout << i << " " << x << " " << length << " " << temp << endl;
        }
    }
    return length;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        colors.push_back(cur);
        occ[cur].push_back(i);
    }

    // if you remove [i, j], you only have to check if there is a k such that i<=k<=j such taht [k, o] would have been more optimal
    vector<pair<int, int>> dp(n+1); // .first = idx of part start, .second = cur_length
    dp[0] = {};

    
    cout << idk(0, 0) << endl;
    colors.clear();
    occ.clear();
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}