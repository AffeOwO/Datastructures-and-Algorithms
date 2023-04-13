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
    
    int n; cin >> n;
    vector<int> nums(n);
    pair<int, int> parity; // first = even, second = odd
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        if(nums[i]%2==0) parity.first++;
        else parity.second++;
    }

    int sol = 0;
    bool cur = true; // t = e, f = o
    while(true) {
        if(cur) {
            cur = not cur;
            if(parity.first == 0) {
                if(parity.second > 1) {
                    parity.first++;
                    parity.second -= 2;
                }
                else {
                    if(parity.second == 1) {
                        sol--;
                    }
                    break;
                }
            }
            parity.first--; sol++;
        }
        else {
            cur = not cur;
            if(parity.second == 0) break;
            parity.second--; sol++;
        }
    }
    cout << sol << endl;

    /*
        if(parity.first == parity.second) cout << parity.first*2 << endl;
    // i hate usaco
    else if(parity.first > parity.second) cout << parity.second*2 + 1 << endl;
    else {
        // just simulate
    }
    */
}