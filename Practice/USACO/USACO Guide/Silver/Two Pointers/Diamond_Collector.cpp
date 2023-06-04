#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; fin >> n >> k;
    vector<int> diamonds(n);
    for(auto &x: diamonds) fin >> x;
    sort(all(diamonds));

    vector<int> showcase(n);
    int l = 0, r = 0;
    while(l<n) {
        while(r<n and diamonds[r]-diamonds[l]<=k) r++;
        showcase[l] = r-l;
        l++;
    }
    vector<int> maxi(n+1);
    for(int i=n-1; i>=0; i--) maxi[i] = max(maxi[i+1], showcase[i]);

    int sol = 0;
    for(int l=0; l<n; l++) sol = max(sol, showcase[l] + maxi[l+showcase[l]]);
    fout << sol << endl;
}