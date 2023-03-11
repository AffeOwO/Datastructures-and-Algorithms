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
#define all(x) (x).begin(), (x).end();
#define MOD 1000000007;

int main() {
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    // Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta
    unordered_map<string, int> hashy{{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};
    while(n--) {
        string temp; int val; fin >> temp >> val;
        hashy[temp] += val;
    }
    int least = 10001, sec_least = 10002;
    int l = 0, sl = 0;
    string cow_l, cow_sl;
    for(auto x: hashy) {
        if(x.second == least) {
            l++;
            cow_l = x.first;
        }
        else if(x.second == sec_least) {
            sl++;
            cow_sl = x.first;
        }
        else if(x.second < least) {
            sec_least = least;
            least = x.second;
            sl = l;
            l = 1;
            cow_sl = cow_l;
            cow_l = x.first;
        }
        else if(x.second < sec_least) {
            sl = 1;
            sec_least = x.second;
            cow_sl = x.first;
        }
    }
    if(sl == 1) fout << cow_sl << endl;
    else fout << "Tie" << endl;
}