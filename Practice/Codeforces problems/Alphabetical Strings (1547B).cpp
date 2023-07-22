#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

string alp = "abcdefghijklmnopqrstuvwxyz";

void solve() {
    string s; cin >> s;
    int n = s.size();
    map<char, int> cnt;
    for(int i=0; i<n; i++) cnt[s[i]]++;
    if(cnt.size() != s.size() or !cnt.count('a')) {
        cout << "NO" << endl;
        return;
    }
    else {
        int pnt1, pnt2;
        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                pnt1 = i-1;
                pnt2 = i+1;
                break;
            }
        }
        for(int i=1; i<n; i++) {
            if(pnt1>=0 and s[pnt1] == alp[i]) {
                pnt1--;
            }
            else if(pnt2<n and s[pnt2] == alp[i]) {
                pnt2++;
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}