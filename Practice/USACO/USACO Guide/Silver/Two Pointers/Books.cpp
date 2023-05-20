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
    
    int n, t; cin >> n >> t;
    vector<int> books(n);
    for(auto &x: books) cin >> x;
    
    int pnt1 = 0, pnt2 = 0, sol = 0, cur = 0;
    while(pnt1 != n) {
        if(cur<=t and pnt2<n) {
            cur += books[pnt2];
            pnt2++;
        }
        else {
            cur -= books[pnt1];
            pnt1++;
        }
        if(cur<=t) sol = max(sol, pnt2-pnt1);
    }
    cout << sol << endl;
}