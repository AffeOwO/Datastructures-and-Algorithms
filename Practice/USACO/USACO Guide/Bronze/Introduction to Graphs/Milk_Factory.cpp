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
    ifstream fin("factory.in");
    ofstream fout("factory.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<int> graph(n);
    for(int i=0; i<n-1; i++) {
        int t, t2; fin >> t >> t2;
        t--;
        graph[t]++;
    }
    int sol = -1;
    for(int i=0; i<n; i++) {
        if(graph[i]==0 and sol != -1) {
            sol = -1;
            break;
        }
        if(graph[i]==0) sol = i+1;
    }
    fout << sol << endl;
}