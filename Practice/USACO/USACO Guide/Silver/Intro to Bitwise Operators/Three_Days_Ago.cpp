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
    
    string s; cin >> s;
    int n = s.size();
    int cur = 0;
    map<int, ll> states;
    states[cur]++;

    for(auto &x: s) {
        cur ^= (1<<(x-'0'));
        states[cur]++;
    }

    ll sol = 0;
    for(auto &x: states) sol += (x.second*(x.second-1)/2);
    cout << sol << endl;
}


/*
if(temp==0) {
        sol = 1 + cnt.first + cnt.second;
        

        cout << sol << endl;
    }
    else {

    }
    */