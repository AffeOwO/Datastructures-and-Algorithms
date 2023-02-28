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

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int nums[n];
    int parity = 0;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        if(nums[i] % 2 == 1) {
            parity++;
        }
        else {
            parity--;
        }
    }
    if(abs(parity) != n) {
        sort(nums, nums+n);
    }
    for(int i=0; i<n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}