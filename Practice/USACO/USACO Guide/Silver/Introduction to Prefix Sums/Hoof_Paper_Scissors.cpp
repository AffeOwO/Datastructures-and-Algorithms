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
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    // if fj never switches, then return n and dont switrch (bessie)
    vector<int> h(n+1), p(n+1), s(n+1);
    int ch = 0, cp=0, cs = 0;
    for(int i=1; i<=n; i++) {
        char temp; fin >> temp;
        switch(temp) {
            case 'H': ch++; break;
            case 'P': cp++; break;
            case 'S': cs++; break;
        }
        h[i] = ch; p[i] = cp; s[i] = cs;
    }
    int sol = 0;
    // O(n), just compare now different ways 
    for(int i=1; i<=n; i++) {
        int bef = max({h[i], p[i], s[i]});
        int aft = max({h[n]-h[i], p[n]-p[i], s[n]-s[i]});
        if(aft+bef>sol) sol = aft+bef;
    }
    fout << sol << endl;
}