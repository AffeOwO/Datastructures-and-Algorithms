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

bool compx(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first>p2.first) return false;
    return true;
}
bool compy(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second>p2.second) return false;
    return true;
}

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<pair<int, int>> coords(n); // x, y
    for(auto &x: coords) fin >> x.first >> x.second;
    vector<pair<int, int>> bx = coords, by = coords;
    sort(all(bx), compx);
    sort(all(by), compy);
    
    ll sol = (bx[n-1].first-bx[0].first)*(by[n-1].second-by[0].second);

    // S
    if(bx[0].first != bx[1].first) {
        ll temp;
        if(bx[0]==by[0]) temp = (bx[n-1].first-bx[1].first)*(by[n-1].second-by[1].second);
        else if(bx[0]==by[n-1]) temp = (bx[n-1].first-bx[1].first)*(by[n-2].second-by[0].second);
        else temp = (bx[n-1].first-bx[1].first)*(by[n-1].second-by[0].second);
        if(temp<sol) sol = temp;
    }
    if(bx[n-1].first != bx[n-2].first) {
        ll temp;
        if(bx[n-1]==by[0]) temp = (bx[n-2].first-bx[0].first)*(by[n-1].second-by[1].second);
        else if(bx[n-1]==by[n-1]) temp = (bx[n-2].first-bx[0].first)*(by[n-2].second-by[0].second);
        else temp = (bx[n-2].first-bx[0].first)*(by[n-1].second-by[0].second);
        if(temp<sol) sol = temp;
    }
    if(by[0].second != by[1].second) {
        ll temp;
        if(by[0]==bx[0]) temp = (bx[n-1].first-bx[1].first)*(by[n-1].second-by[1].second);
        else if(by[0]==bx[n-1]) temp = (bx[n-2].first-bx[0].first)*(by[n-1].second-by[1].second);
        else temp = (bx[n-1].first-bx[0].first)*(by[n-1].second-by[1].second);
        if(temp<sol) sol = temp;
    }
    if(by[n-1].second != by[n-2].second) {
        ll temp;
        if(by[n-1]==bx[0]) temp = (bx[n-1].first-bx[1].first)*(by[n-2].second-by[0].second);
        else if(by[n-1]==bx[n-1]) temp = (bx[n-2].first-bx[0].first)*(by[n-2].second-by[0].second);
        else temp = (bx[n-1].first-bx[0].first)*(by[n-2].second-by[0].second);
        if(temp<sol) sol = temp;
    }
    fout << sol << endl;
}