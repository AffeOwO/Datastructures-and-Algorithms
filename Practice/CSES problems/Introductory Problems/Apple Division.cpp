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
    ll n;
    cin >> n;
    ll arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    bitset<20> temp(pow(2, n));
    ll sol=20*pow(10, 9) + 1;

    for(int i=0; i<pow(2, n); i++) {
        bitset<20> temp(i);
        ll cur = 0;
        for(int i=0; i<n; i++) {
            if(temp.test(i)) {
                cur += arr[i];
            }
            else {
                cur -= arr[i];
            }
        }
        cur = abs(cur);
        if(cur<sol) {
            sol = cur;
        }
    }
    cout << sol << endl;
    // maybe naive approach? 2^20 / 2 possible combinations
}