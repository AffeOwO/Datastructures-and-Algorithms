#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, m;
vector<vector<char>> mat;
vector<vector<vector<bool>>> visited;

// dir: 0 = up; 1 = right; 2 = down; 3 = left
void beam(int y, int x, int dir) {
    // how to avoid loops?
    if(y<0 or x<0 or y>n-1 or x>m-1) return;
    if(visited[y][x][dir]) return;
    visited[y][x][dir] = true;
    if(mat[y][x]=='.') {
        if(dir==0) beam(y-1, x, dir);
        else if(dir==1) beam(y, x+1, dir);
        else if(dir==2) beam(y+1, x, dir);
        else beam(y, x-1, dir);
    }
    else if(mat[y][x]=='-' or mat[y][x]=='|') {
        if(dir==0) {
            if(mat[y][x]=='|') beam(y-1, x, dir);
            else {
                beam(y, x-1, 3);
                beam(y, x+1, 1);
            }
        }
        else if(dir==1) {
            if(mat[y][x]=='-') beam(y, x+1, dir);
            else {
                beam(y-1, x, 0);
                beam(y+1, x, 2);
            }
        }
        else if(dir==2) {
            if(mat[y][x]=='|') beam(y+1, x, dir);
            else {
                beam(y, x-1, 3);
                beam(y, x+1, 1);
            }
        }
        else {
            if(mat[y][x]=='-') beam(y, x-1, dir);
            else {
                beam(y-1, x, 0);
                beam(y+1, x, 2);
            }
        }
    }
    else {
        if(dir==0) {
            if(mat[y][x]=='/') beam(y, x+1, 1);
            else beam(y, x-1, 3);
        }
        else if(dir==1) {
            if(mat[y][x]=='/') beam(y-1, x, 0);
            else beam(y+1, x, 2);
        }
        else if(dir==2) {
            if(mat[y][x]=='/') beam(y, x-1, 3);
            else beam(y, x+1, 1);
        }
        else {
            if(mat[y][x]=='/') beam(y+1, x, 2);
            else beam(y-1, x, 0);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    while(getline(fin, s)) {
        mat.push_back({});
        for(auto &x: s) mat.back().push_back(x);
    }
    n = mat.size(); m = mat[0].size();
    visited.resize(n, vector<vector<bool>>(m, vector<bool>(4)));

    beam(0, 0, 1);

    ll sol1 = 0;
    for(auto &x: visited) {
        for(auto &y: x) {
            for(auto z: y) {
                if(z) {
                    sol1++;
                    break;
                }
            } 
        }
    }
    fout << sol1 << endl;

    ll sol2 = 0;
    for(int i=0; i<n; i++) {
        visited.clear(); visited.resize(n, vector<vector<bool>>(m, vector<bool>(4)));
        ll cur = 0;
        beam(i, 0, 1);
        for(auto &x: visited) {
            for(auto &y: x) {
                for(auto z: y) {
                    if(z) {
                        cur++;
                        break;
                    }
                } 
            }
        }
        sol2 = max(cur, sol2);
        
        visited.clear(); visited.resize(n, vector<vector<bool>>(m, vector<bool>(4)));
        cur = 0;
        beam(i, m-1, 3);
        for(auto &x: visited) {
            for(auto &y: x) {
                for(auto z: y) {
                    if(z) {
                        cur++;
                        break;
                    }
                } 
            }
        }
        sol2 = max(cur, sol2);
    }
    for(int j=0; j<m; j++) {
        visited.clear(); visited.resize(n, vector<vector<bool>>(m, vector<bool>(4)));
        ll cur = 0;
        beam(0, j, 2);
        for(auto &x: visited) {
            for(auto &y: x) {
                for(auto z: y) {
                    if(z) {
                        cur++;
                        break;
                    }
                } 
            }
        }
        sol2 = max(cur, sol2);

        visited.clear(); visited.resize(n, vector<vector<bool>>(m, vector<bool>(4)));
        cur = 0;
        beam(n-1, j, 0);
        for(auto &x: visited) {
            for(auto &y: x) {
                for(auto z: y) {
                    if(z) {
                        cur++;
                        break;
                    }
                } 
            }
        }
        sol2 = max(cur, sol2);
    }

    fout << sol2 << endl;
}