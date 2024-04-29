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
    int n, k; cin >> n >> k;
    map<int, int> cnt;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        int tmp; cin >> tmp;
        cnt[tmp]++;
        nums[i] = tmp;
    }
    vector<pair<int, int>> occ;
    for(auto &x: cnt) occ.push_back({x.second, x.first});

    vector<int> sol(k);
    for(int i=0; i<k; i++) sol[i] = nums[i];
    int l = 1, r = 1e9;
    while(l<=r) {
        int m = (l+r)/2;
        vector<int> tmp;
        for(int i=0; i<occ.size(); i++) {
            for(int j=0; j<occ[i].first/m; j++) tmp.push_back(occ[i].second);
        }
        while(tmp.size()>k) tmp.pop_back();
        if(tmp.size()==k) {
            sol = tmp;
            l = m+1;
        }
        else r = m-1;
    }

    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();   
}