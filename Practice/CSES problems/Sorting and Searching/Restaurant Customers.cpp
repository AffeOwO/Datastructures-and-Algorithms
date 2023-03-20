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
    map<int, int> sweepy;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        sweepy[a]++;
        sweepy[b+1]--;
    }
    int sol = 0, cur = 0;
    for(auto x: sweepy) {
        cur += x.second;
        if(cur>sol) sol = cur;
    }
    cout << sol << endl; 
}