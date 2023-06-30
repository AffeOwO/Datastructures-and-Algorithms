#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll n, h;
vector<ll> bottles;

bool check(ll val) {
    // sort first m elements and then greedy
    vector<ll> idk(val);
    for(int i=0; i<val; i++) idk[i] = bottles[i];
    sort(all(idk));
    ll temp = h;
    for(int i=0; i<val/2; i++) {
        temp -= idk[i*2+1];
    }
    if(val%2) {
        temp -= idk.back();
        ll temp2 = h;
        for(int i=0; i<val/2+1; i++) {
            temp2 -= idk[i*2];
        }
        temp = max(temp, temp2);
    }
    return temp>=0;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> h;
    bottles.resize(n);
    for(auto &x: bottles) cin >> x;
    // n bottles and fridge of height h and width 2
    // find k such that bottles 1, 2, ..., k can be put in the fridge

    ll left = 0, right = n, sol = 0;
    while(left<=right) {
        ll mid = (left+right)/2;
        if(check(mid)) {
            sol = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    cout << sol << endl;
}