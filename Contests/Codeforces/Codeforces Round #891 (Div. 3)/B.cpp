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
    int n = s.size();
    bool idk = false;
    vector<int> temp(n);
    for(int i=0; i<n; i++) {
        if((s[i]-'0')>=5) idk = true;
        temp[i] = s[i]-'0';
    }
    if(!idk) cout << s << endl;
    else {
        if(temp[0]>=5) {
            cout << 1;
            for(int i=0; i<n; i++) cout << 0;
            cout << endl;
            return;
        }
        for(int i=0; i<n; i++) {
            if(temp[i]>=5) {
                int pnt = 1;
                temp[i-1]++;
                while(pnt<i and temp[i-pnt]>=5) {
                    pnt++;
                    temp[i-pnt]++;
                }
                if(temp[0]>=5) {
                    cout << 1;
                    for(int i=0; i<n; i++) cout << 0;
                    cout << endl;
                    return;
                }
                for(int j=0; j<=i-pnt; j++) cout << temp[j];
                for(int j=i-pnt+1; j<n; j++) cout << 0;
                cout << endl;
                return;

            }
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