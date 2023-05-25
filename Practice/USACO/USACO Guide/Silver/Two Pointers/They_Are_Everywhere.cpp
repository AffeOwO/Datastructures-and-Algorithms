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
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    string s; cin >> s; // 0-indexed
    int sol = n;
    set<char> pokemons;
    for(int i=0; i<n; i++) pokemons.insert(s[i]);
    int diff = pokemons.size();
    // just go from left to right
    // shortest substring containing all possible letters
    map<char, int> cur;
    int every = 0;
    int pnt = 0, pnt2 = 0;
    while(pnt2 < n-1) {
        if(every<diff and pnt < n) {
            if(cur[s[pnt]] == 0) every++;
            cur[s[pnt]]++;
            pnt++;
        }
        else {
            cur[s[pnt2]]--;
            if(cur[s[pnt2]]==0) every--;
            pnt2++;
        }
        if(every==diff and pnt-pnt2<sol) sol = pnt-pnt2; 
        //for(auto &x: cur) cout << x.first << "---" << x.second << "--->";
        //cout << pnt2 << " " << pnt << " " << every << endl;
    }

    cout << sol << endl;
}