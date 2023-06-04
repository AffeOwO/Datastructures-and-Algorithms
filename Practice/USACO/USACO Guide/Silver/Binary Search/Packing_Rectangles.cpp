#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll w, h, n; 

bool check(ll m) {
    return (m/w) * (m/h) >= n;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> w >> h >> n;

    ll left = 0, right = 1;
    while(!check(right)) right*=2;
    while(right>left+1) {
        ll mid = left+(right-left)/2;    
        if(check(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}