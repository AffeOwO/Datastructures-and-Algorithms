#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tueten, anzahl_spiele; fin >> tueten >> anzahl_spiele;
    vector<int> spiele(anzahl_spiele);
    for(auto &x: spiele) fin >> x;

    
}