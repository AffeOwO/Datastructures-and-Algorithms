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
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<int> cows(n+2);
    cows[0] = -10000; cows[n+1] = 10000;
    for(int i=1; i<=n; i++) fin >> cows[i];
    sort(all(cows));
    
    // just find distinct cycles?
    // maybe make linked lists and the nthe solution is the amount of heads?
    map<int, int> idk;
    // then count the cows which are never getting a ball 
    for(int i=1; i<=n; i++) {
        if(abs(cows[i]-cows[i-1]) <= abs(cows[i+1]-cows[i])) {
            idk[i] = i-1;
        }
        else {idk[i] = i+1;}
    }
    set<int> sol;
    set<int> two_cycles;
    int temp = 0;
    for(auto &x: idk) {
        sol.insert(x.second);
        if(x.first == idk[x.second]) two_cycles.insert(x.first);
        if((x.first == idk[x.second]) and (max(x.first, x.second) == x.second) and (idk.count(x.second+1) and idk[x.second+1] == x.second)) temp++;
    }
    // find cycles consisting of only 2 node
    for(auto &x: idk) {
        if(two_cycles.count(x.second) and !two_cycles.count(x.first)) temp++;
    }
    if(n==1) fout << 1 << endl;
    else fout << n-sol.size() + two_cycles.size()/2 - temp/2 << endl;
    //cout << n << " " << sol.size() << " " << two_cycles.size() << " " << temp << endl;
    // fuck adhoc
}