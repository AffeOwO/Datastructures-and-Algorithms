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
    
    int n; cin >> n;
    string s; cin >> s;

    string sol = "";
    for(int i=0; i<n; i++) {
        sol += s[i];
        sol += s[i];
    }


    cout << sol << endl;
}