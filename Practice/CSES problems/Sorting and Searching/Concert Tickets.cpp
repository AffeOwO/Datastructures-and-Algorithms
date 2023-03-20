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
    
    int n, m; cin >> n >> m;
    multiset<int> prices;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        prices.insert(temp);
    }
    for(int i=0; i<m; i++) {
        int cur; cin >> cur;
        auto idk = prices.upper_bound(cur);
        if(idk == prices.begin()) cout << -1 << endl;
        else {
            cout << *--idk << endl;
            prices.erase(idk);
        }
    }
}