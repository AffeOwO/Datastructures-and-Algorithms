#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n;
vector<int> cnt;

ll calc(string s, int start, int fin, bool ppa = false) {
    ll sol = 0, tmp = 0;
    pair<int, int> cur;

    for(int i=start; i<fin; i+=2) {
        if(i+1==fin) break;
        if(s[i]=='(') cur.first++;
        else cur.second++;
        if(s[i+1]=='(') cur.first++;
        else cur.second++;
        if(cur.first==cur.second) {
            if(cur.first<=cnt[i]-cnt[start-ppa]) {
                tmp++;
                sol += calc(s, i+2-cur.first-cur.second, i, false);
            }
        }
    }

    return sol + tmp*(tmp+1)/2;
}

void solve() {
    string s; cin >> s;
    // additive
    // only find adjacent brackets which can be switched 
    ll sol = 0;
    n = s.size();
    
    cnt.clear();
    cnt.resize(n);
    for(int i=1; i<n; i++) {
        cnt[i] = cnt[i-1];
        if(s[i-1] == '(') cnt[i]++;
    }

    //cout << calc(s, 1, n) << "...";
    cout << calc(s, 0, n, false) + calc(s, 1, n, true) << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}

/*



    vector<bool> pos(n-1); // switching i and i+1 works -> true
    for(int i=0; i<n-1; i++) {
        if(s[i]!=s[i+1]) {
            if(s[i]=='(') {
                if(cnt[i]>i/2) pos[i] = true;
            }
            else {
                pos[i] = true;
            }
        }
    }
    for(auto x: pos) cout << x << " ";
    cout << endl;
    ll cur = 0;
    for(int i=0; i<n; i+=2) {
        if(pos[i]) cur++;
        else {
            sol += cur*(cur+1)/2;
            cur=0;
        }
    }
    sol += cur*(cur+1)/2;
    cur = 0;
    for(int i=1; i<n; i+=2) {
        if(pos[i]) cur++;
        else {
            sol += cur*(cur+1)/2;
            cur=0;
        }
    }
    sol += cur*(cur+1)/2;

    cout << sol << endl;
*/