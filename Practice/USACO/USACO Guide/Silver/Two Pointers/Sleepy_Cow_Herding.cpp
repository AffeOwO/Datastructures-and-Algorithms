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
    
    int n; cin >> n;
    vector<int> cows(n);
    for(auto &x: cows) cin >> x;
    sort(all(cows));

    
}