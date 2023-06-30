#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    map<int, int> buttons;
    for(int i=0; i<m; i++) {
        int cur; cin >> cur;
        buttons[cur]++;
    }
    // hit the first buttons[i] buttons on try i, then all
    // count occurence of each key
    map<char, int> idk{{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};
    m++;
    for(int i=0; i<n; i++) {
        if(buttons.count(i)) m -= buttons[i];
        idk[s[i]] += m;
    }
    for(auto &x: idk) cout << x.second << " ";
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