#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool cstm(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
    if(p1.first.second<p2.first.second) return true;
    return false;
}

void solve() {
    int n; cin >> n;
    // n friends
    vector<pair<pair<int, int>, int>> friends(n);
    for(int i=0; i<n; i++) {
        int w, h; cin >> w >> h;
        friends[i] = make_pair(make_pair(w, h), i);
        if(w>h) friends[i].first = make_pair(friends[i].first.second, friends[i].first.first);
    }
    // for each friend i, output a friend which can be placed in front of him
    // naive would be O(n^2)
    sort(all(friends), cstm);
    //for(auto &x: friends) cout << x.first.first << " " << x.first.second << endl;
    pair<int, int> mini = make_pair(INT_MAX, friends[0].first.first), cur = {-1, friends[0].second};
    vector<int> sol(n, -1);
    for(int i=1; i<n; i++) {
        if(friends[i-1].first.second == friends[i].first.second) {
            if(mini.second>friends[i].first.first) {
                mini.second = friends[i].first.first;
                cur.second = friends[i].second;
            }
        }
        else {
            if(mini.first>mini.second) {
                mini.first = mini.second;
                cur.first = cur.second;
            }
            mini.second = friends[i].first.first;
            cur.second = friends[i].second;
        }
        //cout << mini.first << " " << mini.second << " " << cur.first << " " << cur.second << endl;
        if(friends[i].first.first>mini.first) sol[friends[i].second] = cur.first+1;
    }

    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}

/*
//
    for(int i=1; i<n; i++) {
        if(friends[i-1].first.first<friends[i].first.first and friends[i-1].first.second<friends[i].first.second) {
            sol[friends[i].second] = friends[i-1].second+1;
        }
        if(sol[friends[i-1].second] != -1 and ) sol[friends[i].second] = sol[friends[i-1].second];
    }

if(p1.first.first<p2.first.first and p1.first.second<p2.first.second) return true;
    return false;
*/
