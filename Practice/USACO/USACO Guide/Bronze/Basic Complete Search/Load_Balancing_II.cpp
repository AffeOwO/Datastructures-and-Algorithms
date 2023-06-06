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
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<pair<int, int>> coords(n);
    for(auto &x: coords) fin >> x.first >> x.second;
    sort(all(coords));

    int sol = 1001;

    

    fout << sol << endl;
}