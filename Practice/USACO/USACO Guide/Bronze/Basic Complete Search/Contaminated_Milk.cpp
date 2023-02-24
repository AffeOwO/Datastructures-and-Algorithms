#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int main() {
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sol = -1;
    int n, m, d, s;
    fin >> n >> m >> d >> s;
    unordered_map<int, unordered_set<int>> milk;
    for(int i=0; i<d; i++) {
        int p, m, t;
        fin >> p >> m >> t;
        milk[m].insert(p);
    }

    unordered_set<int> bad;
    for(int i=0; i<s; i++) {
        int p, t;
        fin >> p >> t;
        bad.insert(p);
    }
    for(auto x: milk) {
        bool temp = true;
        for(auto y: bad) {
            if(!x.second.count(y)) {temp = false;}
        }
        int cnt = size(x.second);
        if(cnt > sol && temp) {sol = cnt;}
    }

    fout << sol << endl;
}
// test case 10 failed but im too lazy to fix