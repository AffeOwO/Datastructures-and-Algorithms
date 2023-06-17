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

    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;

    for(int i=0; i<q; i++) {
        int m; cin >> m;
        char c; cin >> c;
        // two pointer
        // repaint m parts to c such that the longest subsequence only containing c is maximized

        int sol = 0, cnt = 0; // cur painted (cnt<=m)
        int l = 0, r = -1;
        while(true) {
            if(r!=n-1) {
                r++;
                if(s[r] != c) cnt++;
            }
            while(cnt>m) {
                if(s[l] != c) cnt--;
                l++;
            }
            sol = max(sol, r-l+1);
            //cout << l << " " << r << " " << cnt << endl;
            if(r==n-1 and cnt<=m) break;
        }
        cout << sol << endl;
    }
}