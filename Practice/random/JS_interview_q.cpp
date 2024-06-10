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
    //ifstream fin("");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ld> y_sol(1001);
    for(ld y=0; y<=1000; y++) {
        y_sol[y] = -1*y;
        for(ld x=0; x<=y; x++) y_sol[y] += 3*x/2000;
    }

    pair<ld, int> sol;
    for(int y=0; y<=1000; y++) {
        fout << y << " " << y_sol[y] << endl;
        if(y_sol[y]>sol.first) sol = {y_sol[y], y};
    }
    cout << sol.second << " " << sol.first << endl;;
}