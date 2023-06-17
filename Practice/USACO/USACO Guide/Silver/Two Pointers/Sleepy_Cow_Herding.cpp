#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("herding.in");
    ofstream fout("herding.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; fin >> n;
    vector<int> cows(n);
    for(auto &x: cows) fin >> x;
    sort(all(cows));
    vector<int> groups = {1}; // groups of cows
    for(int i=1; i<n; i++) {
        if(cows[i]-cows[i-1]==1) groups.back()++;
        else groups.push_back(1);
    }
    if(groups[0] == n) {
        fout << 0 << endl << 0 << endl;
        return 0;
    }
    
    pair<int, int> sol = {n+1, 0};  // .first = minimum; .second = maximum
    int pnt1 = 0, pnt2 = 0;
    while(true) {
        if(pnt1 != n-1) pnt1++;
        while(cows[pnt1]-n>=cows[pnt2]) pnt2++;
        sol.first = min(sol.first, n-(pnt1-pnt2+1));
        //cout << pnt1 << " " << pnt2 << endl;
        if(pnt1 == n-1 and cows[pnt1]-n<cows[pnt2]) break;
    }
    if(groups[0] == n-1 or groups[1] == n-1) sol.first = 2;
    sol.second = max(cows[n-2]-cows[0], cows[n-1]-cows[1]) - (n-2);


    // cout << sol.first << endl << sol.second << endl;
    fout << sol.first << endl << sol.second << endl;
}