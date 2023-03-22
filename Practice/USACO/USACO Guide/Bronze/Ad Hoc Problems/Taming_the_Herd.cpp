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
    ifstream fin("taming.in");
    ofstream fout("taming.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; fin >> n;
    vector<int> logs(n);
    for(auto &x: logs) fin >> x;
    int cnt = 0, cur = 0;
    pair<int, int> sol;
    bool idk = true;
    if(logs[0] > 0) idk = false;
    for(int i=n-1; i>=0; i--) {
        if(i==0 and cur==0) {
            sol.first++;
            sol.second--;
        }
        if(logs[i] == -1 and cur == 0) sol.second++;
        else if(cur > 0) {
            cur--;
            if(logs[i] != -1 and logs[i] != cur) {
                idk = false;
                break;
            }
        }
        else {
            cur = logs[i];
            sol.first++;
        }
    }
    if(!idk) fout << -1 << endl;
    else fout << sol.first << " " << sol.second+sol.first << endl;
}