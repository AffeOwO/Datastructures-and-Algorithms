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

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    vector<pair<int, int>> factors(n);
    for(int i=0; i<n; i++) {
        ll tmp = nums[i];
        while(tmp%2==0) {
            tmp /= 2;
            factors[i].first++;
        }
        while(tmp%5==0) {
            tmp /= 5;
            factors[i].second++;
        }
    }
    
    vector<vector<int>> dp(n+1, vector<int>(12001, -25000));
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<n; i++) {
        int x = factors[i].second, y = factors[i].first;
        for(int j=min(k-1, (ll)i); j>=0; j--) {
            for(int l=0; l+x<=12000; l++) {
                dp[j+1][l+x] = max(dp[j+1][l+x], dp[j][l]+y);
            }
        }
    }
    int sol = 0;
    for(int i=0; i<=12000; i++) {
        sol = max(sol, min(i, dp[k][i]));
    }
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}

/*
vector<vector<pair<pair<int, int>, pair<int, int>>>> dp(n+1, vector<pair<pair<int, int>, pair<int, int>>>(101));
    // for(auto &x: factors) cout << x.first << " " << x.second << endl;

    for(int i=1; i<=n; i++) {
        for(int j=k; j>0; j--) {
            for(int h=0; h<=100; h++) {
                int tmpfac1 = h-factors[i-1].first, tmpfac2 = h-factors[i-1].second;
                if(tmpfac1>=0 and ((j-1==0 and tmpfac1 == 0) or dp[j-1][tmpfac1].first.first or dp[j-1][tmpfac1].second.first or dp[j-1][tmpfac1].first.second or dp[j-1][tmpfac1].second.second)) {
                    pair<int, int> tmp1 = dp[j-1][tmpfac1].first, tmp2 = dp[j-1][tmpfac1].second;
                    tmp1.first += factors[i-1].first; tmp2.first += factors[i-1].first;
                    tmp1.second += factors[i-1].second; tmp2.first += factors[i-1].second;
                    if(tmp1.first<=tmp1.second and dp[j][h].first.second<tmp1.second) dp[j][h].first = tmp1;
                    else if(tmp1.first>=tmp1.second and dp[j][tmp1.second].second.first<tmp1.first) dp[j][tmp1.second].second = tmp1;
                    if(tmp2.first<=tmp2.second and dp[j][h].first.second<tmp2.second) dp[j][h].first = tmp2;
                    else if(tmp2.first>=tmp2.second and dp[j][tmp2.second].second.first<tmp2.first) dp[j][tmp2.second].second = tmp2;
                }
                if(tmpfac2>=0 and ((j-1==0 and tmpfac2==0) or dp[j-1][tmpfac2].first.first or dp[j-1][tmpfac2].second.first or dp[j-1][tmpfac2].first.second or dp[j-1][tmpfac2].second.second)) {
                    pair<int, int> tmp1 = dp[j-1][tmpfac2].first, tmp2 = dp[j-1][tmpfac2].second;
                    tmp1.first += factors[i-1].first; tmp2.first += factors[i-1].first;
                    tmp1.second += factors[i-1].second; tmp2.first += factors[i-1].second;
                    if(tmp1.first>=tmp1.second and dp[j][h].second.first<tmp1.first) dp[j][h].second = tmp1;
                    else if(tmp1.first<=tmp1.second and dp[j][tmp1.first].first.second<tmp1.second) dp[j][tmp1.first].first = tmp1;
                    if(tmp2.first>=tmp2.second and dp[j][h].second.first<tmp2.first) dp[j][h].second = tmp2;
                    else if(tmp2.first<=tmp2.second and dp[j][tmp2.first].first.second<tmp2.second) dp[j][tmp2.first].first = tmp2;
                }
            }
        }
    }

    int sol = 0;
    for(int i=0; i<100; i++) {
        if(dp[k][i].first.first or dp[k][i].second.first or dp[k][i].first.second or dp[k][i].second.second) {
            sol = i;
            //cout << i << " " << dp[k][i].first << " " << dp[k][i].second << endl;
        }
    }
    cout << sol << endl;
*/