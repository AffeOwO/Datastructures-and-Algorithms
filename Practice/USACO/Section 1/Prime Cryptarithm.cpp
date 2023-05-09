/*
ID: yamato berner (affeowo1)
TASK: crypt1
LANG: C++23
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<int> nums(n);
    for(auto &x: nums) fin >> x;
    set<int> idk;
    for(auto &x: nums) idk.insert(x);

    // xx * xxx, where x*xxx and x0*xxx is 3 digits long and the sum of those two is 4 digits long
    // all digits have to be in nums
    // find all solutions

    int sol = 0;
    // complete search with O(n^5) should work since n < 10
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                for(int l=0; l<n; l++) {
                    for(int m=0; m<n; m++) {
                        // digits 
                        int num1 = (nums[i]*100+nums[j]*10+nums[k]), num2 = (nums[l]*10+nums[m]);
                        int partial1 = nums[m]*num1, partial2 = nums[l]*num1;
                        int end = partial1 + partial2*10;
                        if(partial1<100 or partial1>999 or partial2<100 or partial2>999 or end<1000 or end>9999) continue;
                        if(!idk.count(partial1/100) or !idk.count((partial1/10)%10) or !idk.count(partial1%10) or !idk.count(partial2/100) or !idk.count((partial2/10)%10) or !idk.count(partial2%10)) continue;
                        if(!idk.count(end%10) or !idk.count((end/10)%10) or !idk.count((end/100)%10) or !idk.count(end/1000)) continue;
                        sol++;
                    }
                }
            }
        }
    }


    fout << sol << endl;
}