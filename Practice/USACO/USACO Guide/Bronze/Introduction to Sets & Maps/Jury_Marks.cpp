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
    
    int k, n; cin >> k >> n;
    int k_arr[k], n_arr[n];
    int cur = 0;
    for(int i=0; i<k; i++) {
        int temp; cin >> temp; cur+=temp;
        k_arr[i] = cur;
    }
    for(int i=0; i<n; i++) cin >> n_arr[i];
    int sol = 0;
    unordered_set<int> hashy;
    for(int i=0; i<k; i++) hashy.insert(n_arr[0]-k_arr[i]);
    for(int x: hashy) {
        unordered_set<int> hashy2;
        for(int i=0; i<k; i++) hashy2.insert(x+k_arr[i]);
        bool temp = true;
        for(int i=0; i<n; i++) temp &= hashy2.count(n_arr[i]);
        sol += temp;
    }
    cout << sol << endl;
}