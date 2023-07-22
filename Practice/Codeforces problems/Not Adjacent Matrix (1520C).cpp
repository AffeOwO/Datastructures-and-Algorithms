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
    // n*n matrix with numbers from 1 to n² where adjacent cells cant have adjacent numbers
    if (n==1) cout << 1 << endl;
    else if(n==2) cout << -1 << endl;
    else {
        /*
        1 6 2
        7 3 8
        4 9 5
        */
        pair<int, int> temp = {1, pow(n, 2)/2 + 1};
        if(n%2) temp.second++;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i%2 == j%2) {
                    cout << temp.first << " ";
                    temp.first++;
                }
                else {
                    cout << temp.second << " ";
                    temp.second++;
                }
            }
            cout << endl;
        }
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