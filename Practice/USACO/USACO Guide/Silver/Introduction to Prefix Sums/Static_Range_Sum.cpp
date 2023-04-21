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
    
    int n, q; cin >> n >> q;
    int cur = 0;
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) {
        int temp; cin >> temp; cur+=temp;
        nums[i] = cur;
    }
    while(q--) {
        int q1, q2; cin >> q1 >> q2;
        cout << nums[q2] - nums[q1] << endl;
    }
}