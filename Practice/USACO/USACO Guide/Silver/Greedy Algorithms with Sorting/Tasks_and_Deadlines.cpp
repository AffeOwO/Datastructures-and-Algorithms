#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> tasks(n);
    for(auto &x: tasks) cin >> x.first >> x.second;
    sort(all(tasks));
    ll sol = 0, time = 0;
    for(auto &x: tasks) {
        time += x.first;
        sol += (x.second - time);
    }
    cout << sol << endl;
}