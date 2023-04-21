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
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; fin >> n >> q;
    vector<int> h(n+1), g(n+1), j(n+1);
    int ch = 0, cg = 0, cj = 0;
    for(int i=1; i<=n; i++) {
        int temp; fin >> temp; 
        switch(temp) {
            case 1: ch++; break;
            case 2: cg++; break;
            case 3: cj++; break;
        }
        h[i] = ch; g[i] = cg; j[i] = cj;
    }
    while(q--) {
        int q1, q2; fin >> q1 >> q2;
        q1--;
        fout << h[q2] - h[q1] << " " << g[q2] - g[q1] << " " << j[q2] - j[q1] << endl;
    }

}