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
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; fin >> n >> q;
    vector<int> haybales(n);
    for(auto &x: haybales) fin >> x;
    sort(all(haybales));
    while(q--) {
        int l, r; fin >> l >> r;
        if(l>haybales[n-1] or r<haybales[0]) {
            fout << 0 << endl;
            continue;
        }
        int pnt1, pnt2;
        int left = 0, right = n-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(haybales[mid]>=l) {
                pnt1 = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        left = 0, right = n-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(haybales[mid]<=r) {
                pnt2 = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        //cout << pnt1 << " " << pnt2 << endl;
        fout << pnt2-pnt1+1 << endl;
    }
}