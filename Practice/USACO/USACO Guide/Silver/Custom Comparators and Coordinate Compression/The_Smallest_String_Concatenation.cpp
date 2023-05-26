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

bool comp(string a, string b) {
    return a+b<b+a;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<string> strings(n);
    for(auto &x: strings) cin >> x;
    // sort the vector
    sort(all(strings), comp);

    for(auto &x: strings) cout << x;
    cout << endl;
}