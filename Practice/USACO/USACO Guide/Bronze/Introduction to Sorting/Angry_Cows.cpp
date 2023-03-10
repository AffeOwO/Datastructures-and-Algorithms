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
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    int nums[n];
    for(int i=0; i<n; i++) fin >> nums[i];
    sort(nums, nums+n);
    int sol = 0;
    for(int i=0; i<n; i++) {
        int cur = 1, radius = 1;
        int l = nums[i], r = nums[i];
        for(int j=i; j>=0; j--) {
            if(j==i) continue; // too lazy handling index error stuff
            if(l-radius <= nums[j]) {
                if(j-1 >= 0 && l-radius <= nums[j-1]) {
                    cur++;
                    continue;
                }
                l = nums[j];
                radius++;
                cur++;
            }
        }
        radius = 1;
        for(int j=i; j<n; j++) {
            if(j==i) continue;
            if(r+radius >= nums[j]) {
                if(j+1 < n && r+radius >= nums[j+1]) {
                    cur++;
                    continue;
                }
                r = nums[j];
                radius++;
                cur++;
            }
        }
        if(cur > sol) sol = cur;
    }
    fout << sol << endl;
}