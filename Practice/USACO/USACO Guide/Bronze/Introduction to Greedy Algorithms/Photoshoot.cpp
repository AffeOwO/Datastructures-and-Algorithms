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
    string s; cin >> s; // 1-indexed, H = odd, G = even
    int sol = 0;
    
    for(int i=n-2; i>=0; i-=2) {
        string s_2 = s.substr(i, 2);
        if(s_2[0]==s_2[1]) continue;
        if((s_2 == "GH" and sol % 2 == 0) or (s_2=="HG" and sol%2==1)) sol++;
    }
    cout << sol << endl;
}