#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = size(s);
        int sol = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'B' && sol) {sol--;}
            else {sol++;}
        }
        cout << sol << endl;
    }
}