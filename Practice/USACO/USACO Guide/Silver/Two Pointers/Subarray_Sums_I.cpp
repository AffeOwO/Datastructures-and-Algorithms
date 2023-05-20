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
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    int cur = 0, sol = 0, pnt = 0, pnt2 = 0;
    while(pnt<n) {
        if(cur == x) sol++;
        if(cur<=x and pnt2<n) {
            cur += nums[pnt2];
            pnt2++;
        }
        else if(cur>x or (pnt2==n)) {
            cur -= nums[pnt];
            pnt++;
        }
    }

    cout << sol << endl;
}