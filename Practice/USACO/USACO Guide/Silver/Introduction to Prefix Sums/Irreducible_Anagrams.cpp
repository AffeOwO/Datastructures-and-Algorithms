#include <bits/stdc++.h>

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

    string s; cin >> s;
    int q; cin >> q;
    // 2 strings are anagrams if they have the same chars each appearing the same amount of times
    vector<map<char, int>> pref(s.size()+1);
    for(int i=0; i<s.size(); i++) {
        pref[i+1] = pref[i];
        pref[i+1][s[i]]++;
    }
    while(q--) {
        int l, r; cin >> l >> r;
        if(l==r or s[l-1] != s[r-1]) cout << "Yes" << endl;
        else {
            // atleast 3 different chars in substring
            map<char, int> cur = pref[r];
            for(auto &x: pref[l-1]) cur[x.first] -= x.second;
            int cnt = 0;
            for(auto &x: cur) {
                if(x.second != 0) cnt++;
            }
            if(cnt>2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }   
}