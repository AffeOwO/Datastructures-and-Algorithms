#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int c, n; fin >> c >> n;
    // c chickens; n cows
    vector<int> chickens(c);
    vector<pair<int, int>> cows(n);
    for(auto &x: chickens) fin >> x;
    for(auto &x: cows) fin >> x.first >> x.second;
    sort(all(chickens));
    sort(all(cows));
    int sol = 0;
    // for(auto &x: cows) cout << x.first << " " << x.second << endl;
    
    /*
    for each chicken c, choose the cow where b>=c and b is minimized amongst the possible and a<=c
    */

    vector<bool> ava(n);
    for(int i=0; i<c; i++) {
        // binary search
        // minimum b greater than or equal to c
        // just O(n^2) naive
        pair<int, int> cur = {-1, 1e9+1}; // .first = index; .second = val
        for(int j=0; j<n; j++) {
            if(ava[j]) continue;
            if(cows[j].first > chickens[i]) break;
            if(cows[j].second < cur.second and cows[j].second >= chickens[i]) cur = {j, cows[j].second};
        }
        if(cur.first == -1) continue;
        ava[cur.first] = true;
        sol++;
    }

    fout << sol << endl;
}   

/*
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}

for(int i=0; i<c; i++) {
        while(pnt < c and cows[i].first > chickens[pnt]) pnt++;
        if(pnt == c) break;
        else if(cows[i].second >= chickens[pnt]) {
            sol++;
            pnt++;
        }
    }
*/