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
    pair<int, int> odd, even;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        if(i%2==0) {
            if(temp%2==0) even.first++;
            else even.second++;
        }
        else {
            if(temp%2==0) odd.first++;
            else odd.second++;
        }
    }
    if((odd.first>0 and odd.second>0) or (even.first>0 and even.second>0)) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin>> t;
    while(t--) solve();
}