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

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    unordered_map<int, int> a, c;
    vector<int> b;
    for(int i=0; i<n; i++) {
        int ta; cin >> ta;
        a[ta]++;
    }
    for(int i=0; i<n; i++) {
        int tb; cin >> tb;
        b.push_back(tb);
    }
    for(int i=0; i<n; i++) {
        int tc; cin >> tc;
        c[tc]++;
    }
    ll sol = 0;
    for(int i=0; i<n; i++) {
        if(!a.count(b[i]) || !c.count(i+1)) continue;
        int temp = a[b[i]] * c[i+1];
        sol += temp;
    }
    cout << sol << endl;
}