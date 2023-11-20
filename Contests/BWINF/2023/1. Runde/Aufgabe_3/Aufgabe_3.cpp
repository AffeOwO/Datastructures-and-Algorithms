#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

// Definieren von Variablen
int n, m; 
pair<int, int> A, B;
bool possible = false;
vector<vector<char>> mat1, mat2;
vector<vector<pair<int, char>>> dist1, dist2;
vector<vector<bool>> vis1, vis2;

// custom struct für Koordinaten
struct coords {
    // d = distance; y = y-coord; x = x-coord; f = floor (1, 2)
    int d, y, x, f;
    bool operator<(const coords& c2) const {
        return d>c2.d;
    }
};

int main(int argc, char* argv[]) {
    // input stream setzen
    ifstream fin(argv[1]);

    ios::sync_with_stdio(0);
    cin.tie(0);

    // einlesen der Werte
    fin >> n >> m;
    // Gräße neu festlegen von Vektoren
    mat1.resize(n, vector<char>(m)); mat2.resize(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        string s; fin >> s;
        for(int j=0; j<m; j++) {
            mat1[i][j] = s[j];
            // Falls aktuelles Feld Start oder Ziel ist, diese Koordinaten abspeichern
            if(s[j] == 'A') A = make_pair(i, j);
            else if(s[j] == 'B') B = make_pair(i, j);
        }
    }
    for(auto &x: mat2) {
        string s; fin >> s;
        for(int i=0; i<m; i++) x[i] = s[i];
    }


    // when doing dijkstra, save the previous cell, so you can output the path afterwards
    // movement is shifted one forward here
    dist1.resize(n, vector<pair<int, char>>(m, make_pair(2e9, '_')));
    dist2.resize(n, vector<pair<int, char>>(m, make_pair(2e9, '_')));
    dist1[A.first][A.second].first = 0;
    vis1.resize(n, vector<bool>(m)); vis2.resize(n, vector<bool>(m));

    priority_queue<coords> q; // .first = y, .second = x, .third = 1 or 2 (floor)
    q.push({0, A.first, A.second, 1});
    // Dijkstra
    while(!q.empty()) {
        coords cur = q.top(); q.pop();
        if(cur.f == 1) {
            if(vis1[cur.y][cur.x] or mat1[cur.y][cur.x] == '#') continue;
            vis1[cur.y][cur.x] = true;
            if(cur.y>0 and mat1[cur.y-1][cur.x] != '#' and 1+cur.d<dist1[cur.y-1][cur.x].first) {
                dist1[cur.y-1][cur.x] = {1+cur.d, '^'};
                q.push({1+cur.d, cur.y-1, cur.x, 1});
            }
            if(cur.x>0 and mat1[cur.y][cur.x-1] != '#' and 1+cur.d<dist1[cur.y][cur.x-1].first) {
                dist1[cur.y][cur.x-1] = {1+cur.d, '<'};
                q.push({1+cur.d, cur.y, cur.x-1, 1});
            }
            if(cur.y+1<n and mat1[cur.y+1][cur.x] != '#' and 1+cur.d<dist1[cur.y+1][cur.x].first) {
                dist1[cur.y+1][cur.x] = {1+cur.d, 'v'};
                q.push({1+cur.d, cur.y+1, cur.x, 1});
            }
            if(cur.x+1<m and mat1[cur.y][cur.x+1] != '#' and 1+cur.d<dist1[cur.y][cur.x+1].first) {
                dist1[cur.y][cur.x+1] = {1+cur.d, '>'};
                q.push({1+cur.d, cur.y, cur.x+1, 1});
            }
            if(mat2[cur.y][cur.x] != '#' and 3+cur.d<dist2[cur.y][cur.x].first) {
                dist2[cur.y][cur.x] = {3+cur.d, '!'};
                q.push({3+cur.d, cur.y, cur.x, 2});
            }
        }
        else {
            if(vis2[cur.y][cur.x] or mat2[cur.y][cur.x] == '#') continue;
            vis2[cur.y][cur.x] = true;
            if(cur.y>0 and mat2[cur.y-1][cur.x] != '#' and 1+cur.d<dist2[cur.y-1][cur.x].first) {
                dist2[cur.y-1][cur.x] = {1+cur.d, '^'};
                q.push({1+cur.d, cur.y-1, cur.x, 2});
            }
            if(cur.x>0 and mat2[cur.y][cur.x-1] != '#' and 1+cur.d<dist2[cur.y][cur.x-1].first) {
                dist2[cur.y][cur.x-1] = {1+cur.d, '<'};
                q.push({1+cur.d, cur.y, cur.x-1, 2});
            }
            if(cur.y+1<n and mat2[cur.y+1][cur.x] != '#' and 1+cur.d<dist2[cur.y+1][cur.x].first) {
                dist2[cur.y+1][cur.x] = {1+cur.d, 'v'};
                q.push({1+cur.d, cur.y+1, cur.x, 2});
            }
            if(cur.x+1<m and mat2[cur.y][cur.x+1] != '#' and 1+cur.d<dist2[cur.y][cur.x+1].first) {
                dist2[cur.y][cur.x+1] = {1+cur.d, '>'};
                q.push({1+cur.d, cur.y, cur.x+1, 2});
            }
            if(mat1[cur.y][cur.x] != '#' and 3+cur.d<dist1[cur.y][cur.x].first) {
                dist1[cur.y][cur.x] = {3+cur.d, '!'};
                q.push({3+cur.d, cur.y, cur.x, 1});
            }
        }
    }

    // Lösung ausgeben, falls ein Weg vorhanden ist und den Weg zurückverfolgen und ausgeben.
    if(dist1[B.first][B.second].second=='_') cout << "Punkt B kann nicht erreicht werden" << endl;
    else {
        cout << "Dauer des Weges: " << dist1[B.first][B.second].first << endl << endl;
        // print out path
        pair<int, int> trace = B; int floor = 1;
        while(!(trace.first == A.first and trace.second == A.second and floor == 1)) {
            if(floor == 1) {
                switch(dist1[trace.first][trace.second].second) {
                    case '^':
                        trace.first++;
                        mat1[trace.first][trace.second] = '^';
                        break;
                    case 'v':
                        trace.first--;
                        mat1[trace.first][trace.second] = 'v';
                        break;
                    case '<':
                        trace.second++;
                        mat1[trace.first][trace.second] = '<';
                        break;
                    case '>':
                        trace.second--;
                        mat1[trace.first][trace.second] = '>';
                        break;
                    case '!':
                        floor = 2;
                        mat2[trace.first][trace.second] = '!';
                        break;
                }
            }
            else {
                switch(dist2[trace.first][trace.second].second) {
                    case '^':
                        trace.first++;
                        mat2[trace.first][trace.second] = '^';
                        break;
                    case 'v':
                        trace.first--;
                        mat2[trace.first][trace.second] = 'v';
                        break;
                    case '<':
                        trace.second++;
                        mat2[trace.first][trace.second] = '<';
                        break;
                    case '>':
                        trace.second--;
                        mat2[trace.first][trace.second] = '>';
                        break;
                    case '!':
                        floor = 1;
                        mat1[trace.first][trace.second] = '!';
                        break;
                }
            }
        }


        for(auto &x: mat1) {
            for(auto &y: x) cout << y;
            cout << endl;
        }
        cout << endl;
        for(auto &x: mat2) {
            for(auto &y: x) cout << y;
            cout << endl;
        } 
        cout << endl;
    }
}