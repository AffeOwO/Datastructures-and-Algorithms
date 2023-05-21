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
    
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    vector<map<int, int>> factorized(n);
    for(int i=0; i<n; i++) {
        for(int j=2; j*j<=nums[i]; j++) {
            while(nums[i]%j==0) {
                nums[i] /= j;
                factorized[i][j]++;
            }
            // if(factorized[i][j] == 0) factorized[i].erase(j);
        }
        if(nums[i]>1) factorized[i][nums[i]]++;
        // debuggin
        /*cout << i << "--->";
        for(auto &x: factorized[i]) cout << x.first << " " << x.second << "---";
        cout << endl;*/
    }
    ll sol = 0;

    map<int, int> compute;
    for(auto &x: factorized) {
        int orig = 1, inverse = 1;
        for(auto &y: x) {
            orig *= pow(y.first, y.second%k);
            inverse *= pow(y.first, (k-y.second%k)%k);
        }
        sol += compute[inverse];
        compute[orig]++;
    }
    cout << sol << endl;
}

/*
if(compute.count(inverse)) 

*/