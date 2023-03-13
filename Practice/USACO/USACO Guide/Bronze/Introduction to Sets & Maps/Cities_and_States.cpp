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
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;

    vector<pair<string, string>> pairs;
    for(int i=0; i<n; i++) {
        string city, state; fin >> city >> state;
        city = city.substr(0, 2);
        pairs.push_back({city, state});
    }
    map<string, int> hashy;
    ll sol = 0;
    for(auto [x,y]: pairs) {
        if(x != y) sol += hashy[x+y];
        hashy[y+x]++;
    }

    fout << sol << endl;
}
