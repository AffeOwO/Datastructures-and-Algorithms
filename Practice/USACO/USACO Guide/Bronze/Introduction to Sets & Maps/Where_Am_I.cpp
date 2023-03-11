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
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    string idk; fin >> idk;
    
    for(int i=1; i<=n; i++) {
        unordered_set<string> hashy;
        for(int j=0; j<=n-i; j++) {
            hashy.insert(idk.substr(j, i));
        }
        if(hashy.size() == n-i+1) {
            fout << i << endl;
            break;
        }
    }
}