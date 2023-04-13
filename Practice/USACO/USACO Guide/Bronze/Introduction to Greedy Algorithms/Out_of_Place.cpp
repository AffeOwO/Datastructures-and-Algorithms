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
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;

    vector<int> cows(n);
    for(auto &x: cows) fin >> x;
    
    int sol = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(cows[j+1] < cows[j]) {
                if(!((j != 0 and cows[j]==cows[j-1]) or (j != n-2 and cows[j+1] == cows[j+2]))) sol++;
                swap(cows[j], cows[j+1]);
            }
        }
    }

    fout << sol << endl;
}