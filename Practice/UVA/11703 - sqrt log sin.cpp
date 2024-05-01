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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dp((int)1e6+1);
    dp[0] = 1;
    for(int i=1; i<=1e6; i++) {
        dp[i] = (dp[floor(i-sqrt(i))]+dp[floor(log(i))] + dp[floor(pow(sin(i), 2)*i)])%((int)1e6);
    }

    int cur;
    while(cin >> cur and cur!=-1) {
        cout << dp[cur] << endl;
    }  
}