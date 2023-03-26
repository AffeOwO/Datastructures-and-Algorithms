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
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    string a, b; fin >> a >> b;
    int sol = 0;
    bool cur = false;
    for(int i=0; i<n; i++) {
        if(a[i]==b[i]) {
            if(cur) {
            cur = false;
            sol++;
            }
        }
        else {
            cur = true;
        }
    }
    if(cur) sol++;

    fout << sol << endl;
}