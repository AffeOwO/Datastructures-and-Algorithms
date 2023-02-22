#include <bits/stdc++.h>

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

    bitset<131072> maxi;
    int n = 131072;
    int cnt=0;
    for(int i=2; i<n; i++) {
        if(maxi.test(i)) {continue;}
        cnt += 1;
        //cout << i << endl;        
        if(cnt==10001) {cout << i;}
        for (int j = 2*i; j < n; j += i) {
            maxi.set(j);
        }
    }
}