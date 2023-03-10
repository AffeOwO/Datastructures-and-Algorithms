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
#define all(x) (x).begin(), (x).end();

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x; cin >> n >> x;
    unordered_map<int, int> hashy;
    bool found = false;
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        if(cur>=x) continue;
        if(hashy.count(cur)) {
            cout << hashy[cur] << " " << i+1;
            found = true;
            break;
        }
        hashy[x-cur] = i+1;
    }
    if(!found) cout << "IMPOSSIBLE" << endl;
}