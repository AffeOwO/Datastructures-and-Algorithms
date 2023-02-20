#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; 
    cin >> n;
    int temp = pow(2, n);
    for(int i=0; i<temp; i++) {
        ll value = i ^ (i >> 1);
        bitset<32> idk(value);
        string a = idk.to_string();
        for(int i=32-n; i<32; i++) {
            cout << a[i];
        }
        cout << endl;
    }
}