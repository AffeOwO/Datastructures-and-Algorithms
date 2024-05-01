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

int n, k; 
vector<vector<ll>> dp;

ll ways(int x, int y) {
    if(x<0 or y<0) return 0;
    if(y==1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    ll val = 0;
    for(int i=0; i<=n; i++) val = (val+ways(x-i, y-1))%((ll)1e6); 
    dp[x][y] = val;
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> n >> k;
        if(n==0 and k==0) break;
        dp.clear(); dp.resize(n+1, vector<ll>(k+1, -1));
        // how many ways are there for k numbers to add up to n
        // ways(n, k) = ways(n-x, k-1)+1
        
        cout << ways(n, k)%((ll)1e6) << endl;
    }   
}