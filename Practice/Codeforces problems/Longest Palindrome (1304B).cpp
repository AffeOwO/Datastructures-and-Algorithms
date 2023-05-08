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
    map<string, int> idk;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        idk[s]++;
    }
    string sol="";
    bool alone = false;
    for(auto &x: idk) {
        if(x.second == 0) continue;
        string rev = "";
        for(int i=x.first.size()-1; i>=0; i--) {
            rev += x.first[i];
        }
        if(rev == x.first) {
            if(alone && x.second % 2 == 1) x.second--;
            for(int i=0; i<x.second; i++) {
                // insert x.first in the middle
                sol = sol.substr(0, sol.size()/2) + x.first + sol.substr(sol.size()/2, sol.size()/2);
            }
            if(x.second % 2 == 1) alone = true;
            x.second = 0;
        }
        else if (idk.count(rev) and idk[rev] > 0) {
            int temp = min(x.second, idk[rev]);
            for(int i=0; i<temp; i++) {
                sol = x.first + sol + rev;
            }
            idk[rev] -= temp;
            x.second -= temp;
        }
    }
    cout << sol.size() << endl;
    cout << sol << endl;
}