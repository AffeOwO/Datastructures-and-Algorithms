#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int temp = 1, h, w;
vector<vector<int>> components;
vector<vector<char>> matrix;

void floodfill(int y, int x, char type) {
    if(components[y][x] != -1) return;
    components[y][x] = temp-1;
    if(y>0 and matrix[y-1][x] == type) floodfill(y-1, x, type);
    if(y<h-1 and matrix[y+1][x] == type) floodfill(y+1, x, type);
    if(x>0 and matrix[y][x-1] == type) floodfill(y, x-1, type);
    if(x<w-1 and matrix[y][x+1] == type) floodfill(y, x+1, type);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> h >> w; // height, width
    matrix.resize(h, vector<char>(w));
    int non_snow = 0;
    for(auto &x: matrix) {
        string cur; cin >> cur;
        for(int i=0; i<w; i++) {
            x[i] = cur[i];
            if(x[i] != '.') non_snow++;
        }
    }

    components.resize(h, vector<int>(w, -1));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(components[i][j] == -1) {
                // floodfill same type with temp
            	floodfill(i, j, matrix[i][j]);
                temp++;
            }
        }
    }
    vector<set<int>> edges(temp);
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(matrix[i][j] == '.') continue;
            if(i<h-1 and components[i][j] != components[i+1][j] and matrix[i+1][j] != '.') {
                edges[components[i][j]].insert(components[i+1][j]);
                edges[components[i+1][j]].insert(components[i][j]);
            }
            if(j<w-1 and components[i][j] != components[i][j+1] and matrix[i][j+1] != '.') {
                edges[components[i][j]].insert(components[i][j+1]);
                edges[components[i][j+1]].insert(components[i][j]);
            }
        }
    }
    // now use bfs to find the min max dist
    int sol = 1;

    queue<int> q;
    vector<bool> visited(temp); visited[0] = true;
    vector<int> dist(temp); dist[0] = 1;
    q.push(0);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto x: edges[cur]) {
            if(visited[x]) continue;
            visited[x] = true;
            dist[x] = dist[cur] + 1;
            sol = dist[x];
            q.push(x);
        }
    }

    cout << sol << endl;
}