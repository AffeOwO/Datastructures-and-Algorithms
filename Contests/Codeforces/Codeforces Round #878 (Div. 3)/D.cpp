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
    
    vector<ll> patterns(n);
    for(auto &x: patterns) cin >> x;
    if(n<=3) {
        cout << 0 << endl;
        return;
    }
    sort(all(patterns));
    int pnt2 = 0, pnt3 = 0;
    vector<ll> partitions{patterns[pnt2]-patterns[0], patterns[pnt3]-patterns[pnt2+1], patterns[n-1]-patterns[pnt3+1]};
    bool idk = false;
    while(true) {
        if(pnt3<n-2 and pnt2<=pnt3) {
            vector<ll> temp{patterns[pnt2+1]-patterns[0], patterns[pnt3+1]-patterns[pnt2+2], patterns[n-1], patterns[pnt3+2]};
            if(*max_element(all(temp))<=*max_element(all(partitions))) {
                partitions = temp;
                pnt2++;
                pnt3++;
                idk = true;
            }
        }
        if(pnt3<n-2) {
            vector<ll> temp{patterns[pnt2]-patterns[0], patterns[pnt3+1]-patterns[pnt2+1], patterns[n-1]-patterns[pnt3+2]};
            if(*max_element(all(temp))<=*max_element(all(partitions))) {
                partitions = temp;
                pnt3++;
                idk = true;
            }
        }
        if(pnt2<=pnt3) {
            vector<ll> temp{patterns[pnt2+1]-patterns[0], patterns[pnt3]-patterns[pnt2+2], patterns[n-1]-patterns[pnt3+1]};
            if(*max_element(all(temp))<=*max_element(all(partitions))) {
                partitions = temp;
                pnt2++;
                idk = true;
            }
        }
        
        if(!idk) break;
        idk = false;
    }
    ll sol = *max_element(all(partitions));
    cout << sol/2 + sol%2 << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}