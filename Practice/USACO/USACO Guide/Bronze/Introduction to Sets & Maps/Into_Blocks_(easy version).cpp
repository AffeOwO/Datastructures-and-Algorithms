#include <bits/stdc++.h>

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

    int n, q; cin >> n >> q; // q = 0 since it is the easy version
    vector<int> arr(n);
    map<int, int> cnt;
    map<int, pair<int, int>> f_l; // first; last occurence of element x
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        int x = arr[i];
        cnt[x]++;
        if(!f_l.count(x)) f_l[x].first = i;
        f_l[x].second = i;
    }

    pair<int, int> cur = make_pair(f_l[arr[0]].first, f_l[arr[0]].second);
    set<int> temp;
    int sol = 0;
    for(int i=0; i<n; i++) {
        cur.second = max(cur.second, f_l[arr[i]].second);
        temp.insert(arr[i]);
        if(i==cur.second) {
            int rem = 0;
            for(auto &x: temp) rem = max(rem, cnt[x]);
            sol += ((cur.second-cur.first+1)-rem);
            temp.clear();
            if(i!=n-1) cur = make_pair(f_l[arr[i+1]].first, f_l[arr[i+1]].second);
        }
    }
    cout << sol << endl;
}