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

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<int> hashy;
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        hashy.insert(temp);
    }
    cout << size(hashy) << endl;
}