#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n; // n cows
    // cow i waits behind at most a[i] cows
    vector<int> nums(n);
    for(auto &x: nums) fin >> x;
    // find minimum amount of cows
    sort(all(nums), greater<int>());

    int sol = 0;
    for(int i=0; i<n; i++) {
        if(nums[i]>=sol) sol++;
        else break;
    }


    fout << sol << endl;
}