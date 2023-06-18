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
    
    int n, m; cin >> n >> m;  // n boys and m girls
    vector<ll> boys(n), girls(m); // min sweets each boy presented to a girl; max seets each girl got presented by a boy
    for(auto &x: boys) cin >> x;
    for(auto &x: girls) cin >> x;
    sort(all(boys));
    sort(all(girls));
    ll sol = 0;
    
    // every boy presents sweets for every girl
    
    if(girls[0]<boys[n-1]) {
        cout << -1 << endl;
        return 0;
    }
    int pnt = 0;
    vector<int> cnt(n);
    bool temp = false;
    for(int i=0; i<m; i++) {
        while(pnt < n-1 and boys[pnt+1]<=girls[i]) pnt++;
        cnt[pnt]--;
        if(boys[pnt] == girls[i]) temp = true;
        sol += girls[i];
        //cout << pnt << " " << cnt[pnt] << " " << i << endl;
        if(cnt[pnt] == -1*m and !temp) {
            cnt[pnt]++;
            if(pnt != 0) cnt[pnt-1]--;
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++) {
        sol += ((m+cnt[i])*(boys[i]));
    }
    cout << sol << endl;
}