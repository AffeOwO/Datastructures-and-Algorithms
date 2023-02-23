#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"



bool check(int arr[], int idk, int n) {
    int c = 0;
    for(int i=0; i<n; i++) {
        c+=arr[i];
        if(c==idk) {
            c = 0;
        }
        if(c>idk) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i=n; i>0; i--) {
        if(sum%i==0 && check(arr, sum/i, n)) {
            cout << n-i << endl;
            return;
        }
    } 
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}