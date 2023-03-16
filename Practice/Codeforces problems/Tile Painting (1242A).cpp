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
    
    ll n; cin >> n;
    ll sol = 0, temp;
    for(ll i=2; i*i <= n; i++) {
        if(n%i==0) {
            sol++; temp=i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) sol++, temp = n;
    if(sol==1) cout << temp << endl;
    else cout << 1 << endl;
}