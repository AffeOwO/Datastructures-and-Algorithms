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

int get_factors(int n) {
    int cnt = 0; 
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i == 0) cnt += 2;
    }
    return cnt;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cur = 1;
    while(true) {
        int temp = cur*(cur+1)/2;
        if(get_factors(temp) > 500) {
            cout << cur << " " << temp << endl;
            break;
        }
        cur++;
    }
} 