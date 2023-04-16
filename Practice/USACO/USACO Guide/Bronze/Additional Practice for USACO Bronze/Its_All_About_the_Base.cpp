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

ifstream fin("whatbase.in");
ofstream fout("whatbase.out");

int convert(const string& n, int base) {
    return (n[0]-'0') * pow(base, 2) + (n[1]-'0') * base + (n[2]-'0');
}

void solve() {
    string x, y; fin >> x >> y;
    int bx=10, by=10;
    while(bx<=15000 and by<=15000) {
        int convertedx = convert(x, bx), convertedy = convert(y, by);
        if(convertedx<convertedy) bx++;
        else if(convertedx>convertedy) by++;
        else {
            fout << bx << " " << by << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; fin >> t;
    while(t--) solve();
}