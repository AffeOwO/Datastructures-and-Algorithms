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
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; fin >> n >> k;
    // sweep-line algorithm???
    vector<vector<int>> barn(1000, vector<int> (1000));
    for(int i=0; i<n; i++) {
        int x1, y1, x2, y2; fin >> x1 >> y1 >> x2 >> y2;
        barn[y1][x1]++;
        barn[y2][x1]--;
        barn[y1][x2]--;
        barn[y2][x2]++;
    }
    int sol = 0; 

    for(int y = 0; y<1000; y++) {
        for(int x = 0; x<1000; x++) {
            if(y>0) barn[y][x] += barn[y-1][x];
            if(x>0) barn[y][x] += barn[y][x-1];
            if(x>0 and y>0) barn[y][x] -= barn[y-1][x-1];
            if(barn[y][x] == k) sol++;
        }
    }

    fout << sol << endl;
}