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
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, b; fin >> n >> k >> b;

    vector<int> nums(n);
    for(int i=0; i<=b; i++) {
        int t; fin >> t;
        nums[t-1] = 1;
    }

    vector<int> pref(n+1);
    for(int i=1; i<=n; i++) {
        pref[i] = pref[i-1]+nums[i-1];
    }

    int sol = k;
    for(int i=k; i<=n; i++) {
        int temp = pref[i] - pref[i-k];
        if(temp < sol) sol = temp;
    }
    fout << sol << endl;
}