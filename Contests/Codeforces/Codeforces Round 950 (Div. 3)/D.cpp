#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> g(n-1);
    for(int i=0; i<n-1; i++) g[i] = gcd(a[i], a[i+1]);
    bool tmp = false;
    if(g[0]>g[1]) tmp = true;
    if(g[n-2]<g[n-3]) {
        if(tmp) {
            cout << "NO" << endl;
            return;
        }
        tmp = true;
    }
    /*for(auto &x: g) {
        cout << x << " ";
    }*/
    //cout << endl << endl;
    bool idk = false;
    for(int i=1; i<n-1; i++) {
        if(idk) {
            idk = false;
            continue;
        }
        idk = false;
        if(g[i-1]>g[i]) {
            if(tmp) {
                if(i>2)
                cout << "NO" << endl;
                return;
            }
            tmp = true;
            // rem i or rem i+1
            bool tttt = false, tttt2 = false;
            vector<int> ttt, ttt2;
            for(int j=0; j<n-1; j++) {
                if(j==i) continue;
                if(j+1==i and j+2<n) ttt.push_back(gcd(a[j], a[j+2]));
                else ttt.push_back(gcd(a[j], a[j+1]));
                if(ttt.size()>1 and ttt.back()<ttt[ttt.size()-2]) tttt = true;
            }
            for(int j=0; j<n-1; j++) {
                if(j==i+1) continue;
                if(j==i and j+2<n) ttt2.push_back(gcd(a[j], a[j+2])); 
                else ttt2.push_back(gcd(a[j], a[j+1]));
                if(ttt2.size()>1 and ttt2.back()<ttt2[ttt2.size()-2]) tttt2 = true;
            }
            /*for(auto &x: ttt) cout << x << " ";
            cout << endl;
            for(auto &x: ttt2) cout << x << " ";
            cout << endl << endl;*/

            if(tttt and tttt2) {
                cout << "NO" << endl;
                return;
            }
            if(!tttt2) idk = true;
        }
    }
    cout << "YES" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}