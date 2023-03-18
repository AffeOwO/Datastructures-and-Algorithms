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
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    int nums[n];
    for(int i=0; i<n; i++) fin >> nums[i];
    int sol = n-1;
    for(int i=n-1; i>0; --i) {
        if(nums[i] > nums[i-1]) sol--;
        else break;
    }
    fout << sol << endl;
}