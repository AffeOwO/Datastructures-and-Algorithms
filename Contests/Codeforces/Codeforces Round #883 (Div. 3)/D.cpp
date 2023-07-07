#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; double d, h; cin >> n >> d >> h;
    // bruteforce? (check triangle above cur (how much it covers))
    vector<double> tri(n);
    for(auto &x: tri) cin >> x;
    sort(all(tri));

    double idk = (d*h)/2, sol = idk;
    //cout << sol << endl;
    for(int i=0; i<n-1; i++) {
        double rem = 0;
        if(tri[i+1]<tri[i]+h) {
            // tri[i+1]-tri[i] = overlap height
            // similar triangle -> factor for area is k²
            rem = idk*pow((h-tri[i+1]+tri[i])/h, 2);
        }
        sol += (idk-rem);
        //cout << sol << endl;
    }

    cout << setprecision(12) << fixed << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}