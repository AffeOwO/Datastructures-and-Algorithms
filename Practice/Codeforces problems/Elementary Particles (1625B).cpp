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

void solve() {
    int n; cin >> n;
    int sol = -1;
    // if all numbers are distinct, then it isnt possible but if atleast one number appears more than once then there is one
    // maximum number is the min(difference of indices of two same numbers)
    // -> min(|i-j|) ; a[i] = a[j]
    // maybe make some structure to keep track of when a number appeared the last time
    map<int, int> appeared;
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        if(appeared.count(cur)) {
            int temp = n - (i-appeared[cur]);
            if(temp>sol) sol = temp;
        }
        appeared[cur] = i;
    }

    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}