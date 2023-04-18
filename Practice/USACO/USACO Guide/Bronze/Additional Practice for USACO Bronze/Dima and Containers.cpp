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
    int sol = 0;
    // extraction -> sol += sum of extracted
    // 0 -> extract up to 3 times, other -> add to any container
    vector<int> queries(n);
    for(auto &x: queries) cin >> x;
    
    int last = -1, maxi = -1, nd_maxi = -1, rd_maxi = -1;
    for(int i=0; i<n; i++) {
        if(queries[i] == 0) {
            bool s = false, q = false, d = false; // s -> stack, q -> queue, d -> deck
            for(int j=last+1; j<i; j++) {
                if(queries[j] == maxi and not s) {
                    s = true;
                    cout << "pushStack" << endl;
                }
                else if(queries[j] == nd_maxi and not q) {
                    q = true;
                    cout << "pushQueue" << endl;
                }
                else if(queries[j] == rd_maxi and not d) {
                    d = true,
                    cout << "pushFront" << endl;
                }
                else cout << "pushBack" << endl;
            }
            cout << s+q+d;
            if(s+q+d != 0) cout << " "; 
            if(s) cout << "popStack";
            if(s and (q or d)) cout << " ";
            if(q) cout << "popQueue";
            if(q and d) cout << " ";
            if(d) cout << "popFront";
            last = i;
            cout << endl;
            maxi = nd_maxi = rd_maxi = -1;
        }
        else {
            if(queries[i] >= maxi) {rd_maxi = nd_maxi; nd_maxi = maxi; maxi = queries[i];}
            else if(queries[i] >= nd_maxi) {rd_maxi = nd_maxi; nd_maxi = queries[i];}
            else if(queries[i] >= rd_maxi) {rd_maxi = queries[i];}
        }
    }
    for(int i=last+1; i<n; i++) cout << "pushStack" << endl;
}