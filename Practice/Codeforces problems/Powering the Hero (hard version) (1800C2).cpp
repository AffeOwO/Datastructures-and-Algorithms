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
    int n; cin >> n;
    priority_queue<int> cards;
    ll sol = 0;
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        if(cur==0 and cards.size()!=0) {
            sol += cards.top();
            cards.pop();
        }
        else cards.push(cur);
    }
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