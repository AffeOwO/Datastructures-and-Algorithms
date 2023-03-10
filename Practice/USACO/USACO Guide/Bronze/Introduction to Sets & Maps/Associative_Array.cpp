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
#define all(x) (x).begin(), (x).end();

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q; cin >> q;
    unordered_map<ll, ll> idk;
    while(q--) {
        ll op; cin >> op;
        if(op == 0) {
            ll index; cin >> index;
            cin >> idk[index];
        }
        else {
            ll index; cin >> index;
            if(!idk.count(index)) idk[index] = 0;
            cout << idk[index] << endl;
        }
    }
}