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
    
    string s; cin >> s;

    vector<ll> rem(2019);
    rem[0] = 1;
    ll idk = 1, n = s.size(), num = 0;
    for(int i=n-1; i>=0; i--) {
        num = (num + idk*((ll) s[i]-'0')) % 2019;
        idk = (idk*10)%2019;
        rem[num]++;
    }
    ll sol = 0;
    // nC2
    for(auto &x: rem) { 
        sol += (x*(x-1)/2);
    }

    cout << sol << endl;
}