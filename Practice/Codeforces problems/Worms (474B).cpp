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
    int cur = 0;
    map<int, int> worms;
    for(int i=1; i<=n; i++) {
        int t; cin >> t;
        cur += t;
        worms[cur] = i;
    }
    int m; cin >> m;
    for(int i=0; i<m; i++) {
        int t; cin >> t;
        cout << worms.lower_bound(t)->second << endl;
    }
}