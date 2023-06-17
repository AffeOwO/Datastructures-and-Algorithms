#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    /*
    x = 0 -> anti-poison 
    x = 1 -> poison

    y = tastiness

    health = 0 (if < -1 -> death)
    anti-poison -> health := 0
    poison -> health--

    at the end health >= -1
    */

    vector<pair<int, ll>> meals(n);
    for(auto &x: meals) cin >> x.first >> x.second;
    vector<pair<int, ll>> dp(n+1); // .first = health; .second = tastiness
    dp[0] = {0, 0}; dp[1] = {-1*(meals[0].first == 1), meals[0].second};
    int last_p = -1;
    if(dp[1].first == -1) last_p = 1;
    for(int i=2; i<=n; i++) {
        // dp index = i; normal index = i-1
        pair<int, ll> cur = meals[i-1]; // cur_meal
        if(cur.first == 1 and cur.second <= 0) continue; // why would you eat disgusting poisonous food
        else if(cur.first == 0 and cur.second >= 0) dp[i] = {0, max(dp[i-1].second, dp[i-2].second)+cur.second};
        else if(cur.first == 1 and cur.second > 0) {
            if(dp[i-1].first == 0 and dp[i-2].first == 0) {
                dp[i] = {-1, max(dp[i-1].second, dp[i-2].second)+cur.second};
                last_p = i;
            }
            else if(dp[i-1].first == -1 and dp[i-2].first == -1) {
                
            }
        }
        else if(cur.first == 0 and cur.second < 0) {
            if(dp[i-1].first == -1 and dp[i-2].first == -1) dp[i] = {0, max(dp[i-1].second, dp[i-2].second)+cur.second};
            else if(dp[i-1].first == -1 and dp[i-1].second+cur.second > dp[i-2].second) dp[i] = {0, dp[i-1].second+cur.second};
            else if(dp[i-2].first == -1 and dp[i-2].second+cur.second > dp[i-1].second) dp[i] = {0, dp[i-2].second+cur.second};
        } 
    }


    cout << dp.back().second << endl;
}