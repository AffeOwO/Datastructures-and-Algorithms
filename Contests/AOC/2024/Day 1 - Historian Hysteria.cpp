#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // part one
    vector<int> cnt1, cnt2;
    map<int, int> cnt22;
    for(int i=0; i<1000; i++) {
        int x, y; fin >> x >> y;
        cnt1.push_back(x); cnt2.push_back(y);
        cnt22[y]++;
    }
    sort(all(cnt1)); sort(all(cnt2));
    ll sol = 0;

    for(int i=0; i<1000; i++) sol += abs(cnt1[i]-cnt2[i]);

    fout << sol << endl;

    // part 2
    ll sol2 = 0;
    for(int i=0; i<1000; i++) {
        if(cnt22.count(cnt1[i])) sol2 += cnt1[i]*cnt22[cnt1[i]];
    }
    fout << sol2 << endl;
}