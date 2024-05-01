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
vector<int> cuts;
vector<vector<int>> dp;

int cut(int l, int r) {
    if(r==l+1) return 0;
    int mini = 2e9;
    if(dp[l][r] != -1) return dp[l][r];
    for(int i=l+1; i<r; i++) {
        mini = min(mini, cut(l, i) + cut(i, r) + (cuts[r]-cuts[l]));
    }
    dp[l][r] = mini;
    return mini;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int len;
    while(cin>>len and len) {
        cin >> n;
        cuts.clear();
        cuts.resize(n);
        for(auto &x: cuts) cin >> x;
        cuts.push_back(0); cuts.push_back(len);
        sort(all(cuts));
        dp.clear();
        dp.resize(n+2, vector<int>(n+2, -1));
        cout << "The minimum cutting is " << cut(0, n+1) << "." << endl;
    }   
}