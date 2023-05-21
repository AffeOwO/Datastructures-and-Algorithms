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
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<pair<int, int>> cows(n); // .first = output, .second = cnt of cows
    for(auto &x: cows) fin >> x.second >> x.first;
    sort(all(cows));
    int sol = 0;
    int pnt1 = 0, pnt2 = n-1;
    while(pnt1<=pnt2) {
        int temp = cows[pnt1].first + cows[pnt2].first;
        if(temp>sol) sol = temp;
        if(cows[pnt1].second<cows[pnt2].second) {
            cows[pnt2].second -= cows[pnt1].second;
            pnt1++;
        }
        else if(cows[pnt1].second == cows[pnt2].second) {
            pnt1++;
            pnt2--;
        }
        else {
            cows[pnt1].second -= cows[pnt2].second;
            pnt2--;
        }
    }

    fout << sol << endl;
}