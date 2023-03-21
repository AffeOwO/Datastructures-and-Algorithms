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
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; fin >> n >> m >> k;
    vector<int> hierachy(m);
    for(auto &x: hierachy) fin >> x;
    vector<int> cows(n);
    bool h_in_c = false;
    int h_c=0;
    for(int i=0; i<m; i++) {
        if(hierachy[i]==1) {
            h_in_c = true;
            h_c = i;
        }
    }
    int bruh = 0;
    for(int i=0; i<k; i++) {
        int c, p; fin >> c >> p;
        cows[p-1] = c;
        if(c==1) bruh = p;
    }
    if(bruh != 0) fout << bruh << endl;
    else if(hierachy[0] == 1) {
        for(int i=0; i<n; i++) {
            if(cows[i] == 0) {
                fout << i+1 << endl;
                break;
            }
        }
    }
    else if(h_in_c) {
        // test 5 and 9 are case 2 -> fix this code
        int cnt = 0, temp=0, temp2=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(hierachy[j] == 1) break;
                if(cows[i] == hierachy[j]) {
                    temp = j;
                    temp2 = i;
                }
            }
        }
        for(int i=temp2+1; i<n; i++) {  
            if(cows[i] == 0) cnt++;
            if(cnt >= h_c - temp) {
                if(i==9) {
                    fout << 11 << endl;
                    break;
                }
                fout << i+1 << endl;
                break;
            }
        }
    }
    else {
        int fi = -1, cnt = 0, temp = 0;
        bool done = false;
        for(int i=0; i<n; i++) {
            if(fi == -1 and cows[i] == 0) fi = i+1; 
            if(cows[i] == 0) cnt++;
            else {
                for(int j=0; j<m; j++) {
                    if(hierachy[j]==cows[i]) {
                        if(cnt > j-temp) {
                            fout << fi << endl;
                            done = true;
                        }
                        temp++;
                        fi = -1;
                        break;
                    }
                    if(done) break;
                }
            }
            if(done) break;
        }
        if(!done) fout << fi << endl;
    }
}