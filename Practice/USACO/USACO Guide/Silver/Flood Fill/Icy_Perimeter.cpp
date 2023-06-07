#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n;
vector<vector<char>> grid;// .=empty; #=icecream
vector<vector<bool>> visited;
int cur_area, cur_peri;

void floodfill(int y, int x) {
    if(y<0 or x<0 or x>=n or y>=n or visited[y][x] or grid[y][x] == '.') return;
    visited[y][x] = true;
    cur_area++;
    if(y==0 or grid[y-1][x] == '.') cur_peri++;
    if(x==0 or grid[y][x-1] == '.') cur_peri++;
    if(y==n-1 or grid[y+1][x] == '.') cur_peri++;
    if(x==n-1 or grid[y][x+1] == '.') cur_peri++;

    floodfill(y+1, x);
    floodfill(y, x+1);
    floodfill(y-1, x);
    floodfill(y, x-1);
}

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fin >> n;
    grid.resize(n, vector<char>(n));
    visited.resize(n, vector<bool>(n));
    for(auto &x: grid) {
        for(auto &y: x) fin >> y;
    }
    // min(perimeter) of the icecreams with biggest area
    /*
    1. find all icecream graphs and get the area of each one
    2. calculate the perimeter of those (idk how) and print out the minimum
    */
    vector<pair<int, int>> blob; // .first = area, .second = perimeter
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] and grid[i][j] == '#') {
                cur_area = 0, cur_peri = 0;
                floodfill(i, j);
                blob.push_back({cur_area, cur_peri});
            } 
        }
    }
    sort(all(blob));
    fout << blob.back().first << " ";
    if(blob[0].first == blob.back().first) fout << blob[0].second << endl;
    else {
        for(int i=blob.size()-1; i>0; i--) {
            if(blob[i-1].first != blob.back().first) {
                fout << blob[i].second << endl;
                break;
            }
        }
    }
}