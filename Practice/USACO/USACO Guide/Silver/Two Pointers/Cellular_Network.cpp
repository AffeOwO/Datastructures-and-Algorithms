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
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> cities(n), towers(m);
    for(auto &x: cities) cin >> x;
    for(auto &x: towers) cin >> x;
    sort(all(cities));
    sort(all(towers));

    int pnt = 0; int sol = 0;
    if(m==1) {
        sol = max(abs(cities[0]-towers[0]), abs(cities[n-1]-towers[0]));
        cout << sol << endl;
        return 0;
    } 

    for(int i=0; i<n; i++) {
        while(pnt<m-1 and (cities[i]>towers[pnt+1])) pnt++;
        int temp = min(abs(cities[i]-towers[pnt]), abs(towers[pnt+1]-cities[i]));
        sol = max(sol, temp);
        //cout << temp << endl;
    }
    cout << sol << endl;
}