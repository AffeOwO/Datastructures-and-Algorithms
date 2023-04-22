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
    ifstream fin("stacking.in");
    ofstream fout("stacking.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; fin >> n >> k;
    // sweep line algorithm ?
    map<int, int> sweepy;
    for(int i=0; i<k; i++) {
        int a, b; fin >> a >> b;
        sweepy[a]++;
        sweepy[b+1]--;
    }
    int last = 0, cur = 0;
    vector<int> stacks(n);
    for(auto &x: sweepy) {
        for(int i=last; i<x.first; i++) {
            stacks[i] = cur;
        }
        cur += x.second;
        last = x.first-1;
    }
    

    sort(all(stacks));
    fout << stacks[n/2] << endl;
}