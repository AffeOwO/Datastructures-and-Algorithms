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
    ifstream fin("planting.in");
    ofstream fout("planting.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    int sol = 0;
    map<int, int> graph;
    for(int i=0; i<n-1; i++) {
        int t, t2; fin >> t >> t2;
        graph[t]++;
        graph[t2]++;
        if(graph[t] > sol) sol = graph[t];
        if(graph[t2] > sol) sol = graph[t2];
    }
    fout << sol+1 << endl;
}