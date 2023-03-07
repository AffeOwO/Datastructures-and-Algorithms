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
    int nums[n*2];
    for(int i=0; i<2*n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+2*n);
    int sol = 100000000;
    // prolly O(n^3)
    for(int i=0; i<n*2; i++) {
        for(int j=i+1; j<n*2; j++) {
            int cur = 0;
            //bruh im terrible at this :skull:
            int temp_arr[2];
            int temp_pnt = 0;
            for(int o=0; o<n*2; o++) {
                if(o==i || o==j) continue;
                temp_arr[temp_pnt] = nums[o];
                temp_pnt++;
                if(temp_pnt==2) {
                    temp_pnt = 0;
                    int sum_temp = temp_arr[1] - temp_arr[0];
                    cur += sum_temp;
                }
            }

            if(cur<sol) sol = cur;
        }
    }

    cout << sol << endl;
}