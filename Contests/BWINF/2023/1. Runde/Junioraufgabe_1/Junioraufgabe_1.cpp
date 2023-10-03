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

    int anzahl_tueten, anzahl_spiele; fin >> anzahl_tueten >> anzahl_spiele;
    vector<int> spiele(anzahl_spiele);
    for(auto &x: spiele) fin >> x;

    // every bag should get the same amount of games in it
    vector<vector<int>> tueten(anzahl_tueten);

    int cur = 0;
    for(int i=0; i<anzahl_spiele; i++) {
        for(int j=0; j<spiele[i]; j++) {
            tueten[cur].push_back(i+1);
            cur++;
            cur %= anzahl_tueten;
        }
    }

    for(int i=0; i<anzahl_tueten; i++) {
        cout << "Tüte " << i+1 << ": ";
        for(auto &x: tueten[i]) cout << x << " ";
        cout << endl;
    }
}