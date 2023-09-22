#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    string s; cin >> s;
    // s[i] = ith friends answer {0; 1; ?}
    int n = s.size();
    pair<int, int> cnt; // .first = 0; .second = 1
    for(int i=0; i<n; i++) {
        if(s[i] == '0') cnt.first++;
        else if(s[i] == '1') cnt.second++;
    }
    int unk = n-cnt.first-cnt.second;

    if(unk == n) {
        cout << n << endl;
        return;
    }
    else if(cnt.first == 0) {
        bool temp = false;
        int cnt = 0;
        for(int i=n-1; i>=0; i--) {
            if(temp) break;
            if(s[i]=='1') temp = true;
            cnt++;
        }

        cout << cnt << endl;
        return;
    }

    for(int i=0; i<n; i++) {
        if(s[i] == '0') {
            int cnt = 1;
            bool temp = false;
            for(int j = i-1; j>=0; j--) {
                if(temp) break;
                if(s[j] == '1') temp = true;
                cnt++;
            }
            cout << cnt << endl;
            return;
        }
    }
    cout << "???" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}