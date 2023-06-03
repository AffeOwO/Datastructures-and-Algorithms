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
    if(n<pow(10, 3)) cout << n << endl;
    else if(n<pow(10, 4)) cout << n-n%10 << endl;
    else if(n<pow(10, 5)) cout << n-n%100 << endl;
    else if(n<pow(10, 6)) cout << n-n%1000 << endl;
    else if(n<pow(10, 7)) cout << n-n%10000 << endl;
    else if(n<pow(10, 8)) cout << n-n%100000 << endl;
    else cout << n-n%1000000 << endl;
}