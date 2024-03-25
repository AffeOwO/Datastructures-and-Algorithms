#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n;
vector<ll> nums;
vector<vector<ll>> temp;

ll solve(ll l, ll r) {
    if(temp[l][r]!=-1) return temp[l][r];
    if(l==r) return 0;
    temp[l][r] = nums[r]-nums[l]+min(solve(l+1, r), solve(l, r-1));
    return temp[l][r]; 
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    nums.resize(n); temp.resize(n, vector<ll>(n, -1));
    for(auto &x: nums) cin >> x;
    sort(all(nums));

    if(n==1) cout << 0 << endl;
    else cout << solve(0, n-1) << endl;

}


/*
for(int i=0; i<n-1; i++) {
            ll cur = (n-1)*le[i], l = i, r = i, tmp;
            cout << cur << " ";
            while(l!=0 or r!=n-2) {
                tmp = n-2-(r-l);
                if(l==0) {
                    r++;
                    cur += le[r]*tmp;
                }
                else if(r==n-2) {
                    l--;
                    cur += le[l]*tmp;
                }
                else {
                    if(le[l-1]<le[r+1]) {
                        l--;
                        cur += le[l]*tmp;
                    }
                    else {
                        r++;
                        cur += le[r]*tmp;
                    }
                }
                cout << cur << " ";
            }
            cout << endl;
            sol = min(sol, cur);
        }
*/