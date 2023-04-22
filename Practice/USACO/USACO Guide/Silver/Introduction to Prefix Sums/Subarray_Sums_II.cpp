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
    
    int n, x; cin >> n >> x;
    ll cnt = 0;
    vector<ll> nums(n+1);
    for(int i=1; i<=n; i++) {
        int temp; cin >> temp;
        cnt += temp;
        nums[i] = cnt;
    }

    map<ll, ll> idk;
    ll sol = 0;
    for(int i=0; i<=n; i++) {
        // cout << nums[i] << " ";
        sol += idk[nums[i]-x];
        idk[nums[i]]++;
    }
    // cout << endl;
    cout << sol << endl;
}