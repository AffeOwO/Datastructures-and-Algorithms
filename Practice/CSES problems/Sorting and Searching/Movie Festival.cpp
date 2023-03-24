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

bool custom_comp(pair<int, int> &temp, pair<int, int> &temp2) {
    if(temp.second==temp2.second) return temp.first < temp2.first;
    return temp.second < temp2.second;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, int>> movies;
    for(int i=0; i<n; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        movies.push_back(temp);
    }
    sort(all(movies), custom_comp);
    int sol = 0, cur = -1;

    for(auto &x: movies) {
        if(x.first >= cur) {
            sol++;
            cur = x.second;
        }
    }

    cout << sol << endl;
}