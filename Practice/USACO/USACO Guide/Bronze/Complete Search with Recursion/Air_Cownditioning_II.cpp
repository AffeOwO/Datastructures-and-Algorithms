#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> air_conds;
    map<int, int> sweepy;
    for(int i=0; i<n; i++) {
        int t, t1, t2; // range(start -> end), needed
        cin >> t >> t1 >> t2;
        sweepy[t] -= t2;
        sweepy[t1+1] += t2;
    }
    
    for(int i=0; i<m; i++) {
        int t, t1, t2, t3; // range(start -> end), reduceing, cost
        cin >> t >> t1 >> t2 >> t3;
        air_conds.push_back({t, t1, t2, t3});
    }
    int sol = 1000000;
    for(int i=0; i<pow(2,m); i++) {
        bitset<10> idk(i);
        int cur = 0;
        bool works = true;
        map<int, int> sweepy_cp = sweepy;
        for(int i=0; i<10; i++) {
            if(idk.test(i)) {
                cur += air_conds[i][3];
                sweepy_cp[air_conds[i][0]] += air_conds[i][2];
                sweepy_cp[air_conds[i][1]+1] -= air_conds[i][2];
            }
        }
        int temp = 0;
        for(auto x: sweepy_cp) {
            if(temp < 0) works = false;
            temp += x.second;
        }
        if(cur<sol && works) sol = cur;
    }
    cout << sol << endl;
}