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

struct interaction {
    int t, x, y;
};
bool operator<(const interaction inter1, const interaction inter2) {return inter1.t<inter2.t;}

int main() {
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, T; fin >> N >> T; // n = cows, t = interactions
    string s; fin >> s;

    vector<interaction> interactions(T);
    for(auto &inter: interactions) fin >> inter.t >> inter.x >> inter.y;
    sort(all(interactions));

    vector<bool> infected(N);
    unordered_set<int> possible;
    pair<int, int> K{T, -1}; // .first = min, .second = max
    
}