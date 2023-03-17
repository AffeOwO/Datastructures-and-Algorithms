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

unordered_set<int> sol;

void solve(int day, int l_cnt, vector<int> l_vec, int r_cnt, vector<int> r_vec) {
    if(day==4) {
        sol.insert(l_cnt);
        return;
    }
    for(int i=0; i<l_vec.size(); i++) {
        int temp = l_vec[i];
        vector<int> new_l = l_vec;
        new_l.erase(begin(new_l)+i);
        vector<int> new_r = r_vec;
        new_r.push_back(temp);
        
        solve(day+1, r_cnt + temp, new_r, l_cnt - temp, new_l);

    }
    
}

int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> vec1(10), vec2(10);
    for(int i=0; i<10; i++) fin >> vec1[i];
    for(int i=0; i<10; i++) fin >> vec2[i];

    solve(0, 1000, vec1, 1000, vec2);

    
    //for(auto x: sol) cout << x << " ";
    fout << sol.size() << endl;
}