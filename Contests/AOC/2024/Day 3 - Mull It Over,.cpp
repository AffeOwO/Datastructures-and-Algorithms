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

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // part 1
    string s="", t;
    for(t; getline(fin, t);) {
        s+=t;
    }
    int n=s.size();
    ll sol = 0;
    for(int i=0; i<n-3; i++) {
        if(s.substr(i, 4)=="mul(") {
            int k = i+4, x=0, y=0;
            while(k<n and 0<=s[k]-'0' and s[k]-'0'<=9) {
                x=10*x+(s[k]-'0');
                k++;
            }
            if(k==n or s[k]!=',') continue;
            k++;
            while(k<n and 0<=s[k]-'0' and s[k]-'0'<=9) {
                y=10*y+(s[k]-'0');
                k++;
            }
            if(k==n or s[k]!=')') continue;
        	sol += x*y;
        }
    }
    fout << sol << endl;

    // part 2;
    ll sol2 = 0;
    bool val = true;
    for(int i=0; i<n-3; i++) {
        if(val and s.substr(i, 4)=="mul(") {
            int k = i+4, x=0, y=0;
            while(k<n and 0<=s[k]-'0' and s[k]-'0'<=9) {
                x=10*x+(s[k]-'0');
                k++;
            }
            if(k==n or s[k]!=',') continue;
            k++;
            while(k<n and 0<=s[k]-'0' and s[k]-'0'<=9) {
                y=10*y+(s[k]-'0');
                k++;
            }
            if(k==n or s[k]!=')') continue;
        	sol2 += x*y;
        }
        if(i<n-6 and s.substr(i,7)=="don't()") val = false;
        else if(s.substr(i, 4)=="do()") val = true;
    }
    fout << sol2 << endl;
}