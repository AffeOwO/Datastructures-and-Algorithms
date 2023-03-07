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
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<pair<int, int>> cows;
    for(int i=0; i<n; i++) {
        pair<int, int> temp;
        fin >> temp.first >> temp.second;
        cows.push_back(temp);
    }
    sort(cows.begin(), cows.end());
    int sol = 0;

    for(auto x: cows) {
        if(sol<x.first) sol = x.first;
        sol += x.second;
    }

    fout << sol << endl;
}