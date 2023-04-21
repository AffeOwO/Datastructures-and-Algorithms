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
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<int> cows(n+1);
    int cur = 0;
    map<int, pair<int, int>> sol;
    for(int i=1; i<=n; i++) {
        int temp; fin >> temp;
        cur = (cur+temp)%7;
        if(!sol.count(cur)) {
            sol[cur].first = i;
        }
        sol[cur].second = i;
    }
    int idk = 0;
    for(auto &x: sol) {
        int temp = x.second.second - x.second.first;
        if(temp > idk) idk = temp;
    }
    fout << idk << endl;
}