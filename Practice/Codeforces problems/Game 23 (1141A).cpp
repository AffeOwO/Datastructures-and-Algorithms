#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    if(m%n!=0) {
        cout << -1 << endl;
        return 0;    
    }
    int temp = m/n;
    int sol = 0;
    while(temp != 1) {
        if(temp%2!=0 && temp%3!=0 && temp!=1) {
            cout << -1 << endl;
            return 0;
        }
        if(temp%2==0) {
            temp /= 2;
            sol++;
        }
        if(temp%3==0) {
            temp /=3;
            sol++;
        }
    }
    cout << sol << endl;
}