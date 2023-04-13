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
    ifstream fin("race.in");
    ofstream fout("race.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, n; fin >> k >> n;
    for(int i=0; i<n; i++) {
        int x; fin >> x;
        int sol = 0, r = k, s = 1;
        while(r>0 and s<x) {
            sol++;
            r -= s;
            s++;
        }
        bool temp = true;
        while(r>0) {
            sol++;
            r -= s;
            if(temp == false) s++;
            temp = not temp;
        }
        fout << sol << endl;
    }

    /*
    int k, n; fin >> k >> n;
    for(int i=0; i<n; i++) {
        int x; fin >> x;
        // if you keep increasing every second then you travel s(s+1)/2 meters after s seconds 
        // iterate from both sides
        if(x*(x+1)/2 >= k) {
            int idk = 0;
            for(int i=1; i<=x; i++) {
                idk += i;
                if(idk>=k) {
                    fout << i << endl;
                    break;
                }
            }
        }
        else {
            // rewrite it
            int temp = x*(x+1)/2;
            int to_run = k - temp - x;
            if(to_run <= 0) {
                fout << x+1 << endl;
                continue;
            }
            int sol = x+1;
            while(true) {
                x++;
                sol+=2;
                if(to_run<=x) {
                    sol--;
                    
                }
                to_run -= (2*x);
                if(to_run <= 0) break;
            }
            fout << sol << endl;
        }
    }
    */
}