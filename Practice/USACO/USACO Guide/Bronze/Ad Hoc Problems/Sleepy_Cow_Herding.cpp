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
    ifstream fin("herding.in");
    ofstream fout("herding.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int nums[3]; fin >> nums[0] >> nums[1] >> nums[2];
    sort(nums, nums+3);
    pair<int, int> sol; // mini, maxi
    if(nums[2]-nums[0] == 2) sol.first = 0;
    else if(nums[1] - nums[0] == 2 || nums[2] - nums[1] == 2) sol.first = 1;
    else sol.first = 2;
    sol.second = max(nums[2]-nums[1]-1, nums[1]-nums[0]-1);
    fout << sol.first << endl << sol.second;
}