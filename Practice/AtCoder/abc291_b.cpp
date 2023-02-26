//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

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
    
    int n; cin >> n;
    int nums[5*n];
    for(int i=0; i<5*n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+5*n);
    int m = 3*n;
    double sol = 0;
    for(int i=n; i<4*n; i++) {
        sol += nums[i];
    }
    cout << sol / m << endl;
}