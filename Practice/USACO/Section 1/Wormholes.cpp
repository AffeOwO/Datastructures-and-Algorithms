#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; fin >> n;
    map<int, int> cnt;
    for(int i=0; i<n; i++) {
        int x, y; fin >> x >> y;
        cnt[y]++;
    }
    
}