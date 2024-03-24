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

bool divi = true; 

int calc(int x, int y, int ope) {
    switch(ope) {
        case 0: return x+y;
        case 1: return x-y; 
        case 2: return x*y;
        case 3:
            if(y==0 or x%y!=0) {
                divi = false;
                return 0;
            }
            return x/y;
    }
    return 0;
}

void solve() {
    vector<int> nums(4); sort(all(nums));
    for(auto &x: nums) cin >> x;
    int sol = -100, idk;
    do{
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                for(int k=0; k<4; k++) {
                    idk = calc(calc(calc(nums[0], nums[1], i), nums[2], j), nums[3], k);
                    if(idk>sol and idk<=24 and divi) sol = idk;
                    if(!divi) divi = true;
                    idk = calc(calc(nums[0], nums[1], i), calc(nums[2], nums[3], k), j);
                    if(idk>sol and idk<=24 and divi) sol = idk;
                    if(!divi) divi = true;
                    idk = calc(calc(nums[0], calc(nums[1], nums[2], j), i), nums[3], k);
                    if(idk>sol and idk<=24 and divi) sol = idk;
                    if(!divi) divi = true;
                    idk = calc(nums[0], calc(calc(nums[1], nums[2], j), nums[3], k), i);
                    if(idk>sol and idk<=24 and divi) sol = idk;
                    if(!divi) divi = true;
                    idk = calc(nums[0], calc(nums[1], calc(nums[2], nums[3], k), j), i);
                    if(idk>sol and idk<=24 and divi) sol = idk;
                    if(!divi) divi = true;
                }
            }
        }
    }while(next_permutation(all(nums)));

    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n; 
    while(n--) solve();
}