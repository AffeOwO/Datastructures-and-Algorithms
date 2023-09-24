#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; fin >> n >> m;
    vector<pair<ll, ll>> intervals(m);
    for(auto &x: intervals) fin >> x.first >> x.second;
    sort(all(intervals));

    ll left = 1, right = intervals.back().second, sol = 1;
    while(left<=right) {
        ll mid = (left+right)/2;
        // cout << left << " " << right << " " << mid << endl;
        int rem = n-1;
        ll cur = intervals[0].first+mid;
        for(int i=0; i<m; i++) {
            while(cur<=intervals[i].second) {
                rem--;
                if(rem<=0) break;
                cur = max(cur+mid, intervals[i].first+mid);
            }
            if(rem<=0) break;
        }


        if(rem<=0) {
            sol = mid;
            left = mid+1;
        }
        else right = mid-1;
    }

    fout << sol << endl;
}