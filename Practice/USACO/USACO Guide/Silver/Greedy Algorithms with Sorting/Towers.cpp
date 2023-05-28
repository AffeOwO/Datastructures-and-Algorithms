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
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    // just look for decreasing subsequences while keeping an eye on the index
    multiset<int> sol{-1};
    for(auto &x: nums) {
        if(*--sol.end() <= x) sol.insert(x);
        else {
            sol.erase(sol.upper_bound(x));
            sol.insert(x);
        }
        /*
        cout << *--sol.end() << "-->";
        for(auto &x: sol) cout << x << " ";
        cout << endl;
        */
    }
    cout << sol.size()-1 << endl;
}