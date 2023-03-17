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

int maxi=0;

int calculate(int operation, int num1, int num2) {
    switch(operation) {
        case 0: return num1 + num2;
        case 1: return num1 - num2;
        case 2: return num1 * num2;
        case 3: return num1 / num2;
    }
    cout << operation << " ";

    return -1;
}


void solve(vector<int> nums) {
    // this code should be a crime
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int o=0; o<4; o++) {
                int cur = nums[0];
                if(cur % nums[1] != 0 && i == 3) continue;
                cur = calculate(i, cur, nums[1]);
                if(cur % nums[2] != 0 && j == 3) continue;
                cur = calculate(j, cur, nums[2]);
                if(cur % nums[2] != 0 && o == 3) continue;
                cur = calculate(o, cur, nums[3]);
                if(cur>maxi && cur <= 24) maxi = cur;
            }
        }
    }
    

}

/*
right now, iterate through all permutaions of numbers and then try all combinations of signs, 
assuming that - is only used to substract and not for negative numbers like -x

for all permutations (4! -> 24), try all sign combinations
for each order, there are 4^3 -> 64 different sign combinations

-> O(4^n) (4! is a constant)
*/

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n; 
    int temp;
    while(n--) {
        vector<int> nums(4); cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
        maxi = 0;
        do {
            solve(nums);
        } while(next_permutation(nums.begin(), nums.end()));

        cout << maxi << endl;
    }
}