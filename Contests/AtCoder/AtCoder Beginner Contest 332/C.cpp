#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m; // schedule of n days
    string s; cin >> s; // schedule 
    // 0 = nothing; 1 = eat out; 2 = cp contest
    // m plan shirts
    // needs logo ts for cp contests; but they can be worn on eat days too
    pair<int, int> shirts = make_pair(m, 0); // .first = plain; .second = logo
    pair<int, int> cur = shirts;
    for(auto &x: s) {
        if(x == '0') cur = shirts;
        else if(x=='1') {
            if(cur.first>0) cur.first--;
            else {
                if(cur.second>0) cur.second--;
                else shirts.second++;
            }
        }
        else {
            if(cur.second>0) cur.second--;
            else shirts.second++;
        }
    }
    cout << shirts.second << endl;
}