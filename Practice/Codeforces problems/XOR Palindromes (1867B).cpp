#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    // for each x, 0<=x<=n; 1 if there is a binary string with x 1s such that the string is good
    // you can change the state with one 1
    
    if(n%2==0) {
        pair<int, int> states; // .first = s[i] == s[n-i-1]; .second = s[i] != s[n-i-1]
        for(int i=0; i<n/2; i++) {
            if(s[i] == s[n-i-1]) states.first++;
            else states.second++;
        }
        for(int i=0; i<=n; i++) {
            if(i>=states.second and (i-states.second) % 2 == 0 and (i-states.second)/2<=states.first) cout << 1;
            else cout << 0;
        }
    }
    else {
        pair<int, int> states;
        for(int i=0; i<n/2; i++) {
            if(s[i] == s[n-i-1]) states.first++;
            else states.second++;
        }
        for(int i=0; i<=n; i++) {
            if(i>=states.second and (i-states.second)/2<=states.first) cout << 1;
            else cout << 0;
        }
    }
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}