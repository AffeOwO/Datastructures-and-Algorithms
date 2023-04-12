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
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<vector<char>> field(n, vector<char> (n));
    for(int i=0; i<n; i++) {
        string idk; fin >> idk;
        for(int j=0; j<n; j++) {
            field[i][j] = idk[j];
        }
    }

    vector<int> state(n);
    int sol = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if((state[j]%2==0 and field[i][j]=='1') or (state[j]%2==1 and field[i][j]=='0')) {
                sol++;
                for(int k=0; k<=j; k++) state[k]++;
            }
        }
    }

    fout << sol << endl;
}