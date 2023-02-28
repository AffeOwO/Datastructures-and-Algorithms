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
    string s; cin >> s;
    stack<int> idk;
    int temp = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '(') {
            idk.push(1);
            temp++;
        }
        else if(s[i] == ')' && idk.size() >= 1) {
            idk.pop();
        }
        if(s[i] == ')') {
            temp--;
        }
    }
    if(idk.size() <= 1 && temp == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}