#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

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
    
    int a, b, c; cin >> a >> b >> c;
    int m; cin >> m;
    vector<ll> usb, ps;
    for(int i=0; i<m; i++) {
        ll p; string s; cin >> p >> s;
        if(s == "USB") usb.push_back(p);
        else ps.push_back(p);
    }
    sort(all(usb)); sort(all(ps));
    if(usb.size()<a) a = usb.size();
    if(ps.size()<b) b = ps.size();
    ll sol = 0;
    ll pntu = a, pntp = b;
    for(int i=0; i<a; i++) sol += usb[i];
    for(int i=0; i<b; i++) sol += ps[i];
    for(int i=0; i<c; i++) {
        if(pntu >= usb.size() and pntp >= ps.size()) break;
        else if(pntu >= usb.size()) {
            sol += ps[pntp];
            pntp++;
        }
        else if(pntp >= ps.size()) {
            sol += usb[pntu];
            pntu++;
        }
        else {
            if(ps[pntp] < usb[pntu]) {
                sol += ps[pntp];
                pntp++;
            }
            else {
                sol += usb[pntu];
                pntu++;
            }
        }
    }

    cout << pntu + pntp << " " << sol << endl;
}