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
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, k, m; fin >> x >> y >> k >> m;
    vector<vector<int>> states(y+1, vector<int>(x+1, k+1));
    states[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if(states[cur.first][cur.second]+1<states[cur.first][0]) {
            q.push({cur.first, 0});
            states[cur.first][0] = states[cur.first][cur.second]+1;
        }
        if(states[cur.first][cur.second]+1<states[0][cur.second]) {
            q.push({0, cur.second});
            states[0][cur.second] = states[cur.first][cur.second]+1;
        }
        if(states[cur.first][cur.second]+1<states[cur.first][x]) {
            q.push({cur.first, x});
            states[cur.first][x] = states[cur.first][cur.second]+1;
        }
        if(states[cur.first][cur.second]+1<states[y][cur.second]) {
            q.push({y, cur.second});
            states[y][cur.second] = states[cur.first][cur.second]+1;
        }
        if(cur.second+cur.first<=y) {
            if(states[cur.second+cur.first][0]>states[cur.first][cur.second]+1) {
                q.push({cur.first+cur.second, 0});
                states[cur.second+cur.first][0] = states[cur.first][cur.second]+1;
            }
        }
        else {
            if(states[y][cur.second-y+cur.first]>states[cur.first][cur.second]+1) {
                q.push({y, cur.first+cur.second-y});
                states[y][cur.first+cur.second-y] = states[cur.first][cur.second]+1;
            }
        }
        if(cur.second+cur.first<=x) {
            if(states[0][cur.first+cur.second]>states[cur.first][cur.second]+1) {
                q.push({0, cur.first+cur.second});
                states[0][cur.first+cur.second] = states[cur.first][cur.second]+1;
            }
        }
        else {
            if(states[cur.first+cur.second-x][x]>states[cur.first][cur.second]+1) {
                q.push({cur.first+cur.second-x, x});
                states[cur.first+cur.second-x][x] = states[cur.first][cur.second]+1;
            }
        }
    }
    int sol = m;
    for(int i=0; i<=y; i++) {
        for(int j=0; j<=x; j++) {
            if(states[i][j]<=k and abs(m-(i+j))<sol) sol = abs(m-(i+j));
        }
    }
    fout << sol << endl;
}