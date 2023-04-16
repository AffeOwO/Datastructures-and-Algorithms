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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int sol;
    //make a counter?; you need k different palindromes, thus shortest >= ceil(n/k)
    map<char, int> counter;
    for(int i=0; i<n; i++) counter[s[i]]++;
    pair<int, int> idk; // 2s, 1s
    for(auto &x: counter) {
        idk.first += (x.second/2); idk.second += (x.second%2);
    }
    sol = 2*(idk.first/k);
    idk.second += 2*(idk.first%k);
    if(idk.second>=k) sol++;
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}