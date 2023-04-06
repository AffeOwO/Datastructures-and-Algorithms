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
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; fin >> n >> k;
    int a1, a2, b1, b2; fin >> a1 >> a2 >> b1 >> b2;
    vector<int> cows(n);
    for(int i=0; i<n; i++) cows[i] = i+1;
    vector<vector<int>> sequences;
    sequences.push_back(cows);

    int cnt = 0;
    while(true) {
        k--;
        cnt++;
        //for(auto &x: cows) cout << x << " ";
        //cout << endl;
        for(int i=0; i<(a2-a1+1)/2; i++) {
            swap(cows[a1-1+i], cows[a2-1-i]);
        }
        //for(auto &x: cows) cout << x << " ";
        //cout << endl;
        for(int i=0; i<(b2-b1+1)/2; i++) {
            swap(cows[b1-1+i], cows[b2-1-i]);
        }
        /*
        for(auto &x: cows) cout << x << " ";
        cout << endl;
        cout << endl;
        */
        if(k==0) {
            for(auto &x: cows) fout << x << endl;
            break;
        }
        if(cows == sequences[0]) {
            k %= cnt;
            for(auto &x: sequences[k]) fout << x << endl;
            break;
        }
        sequences.push_back(cows);
    }
}