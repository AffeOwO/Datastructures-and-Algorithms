#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

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
    
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m)), times(n, vector<int>(m));
    // keep a second vector for time 

    for(int i=0; i<k; i++) {
        int x, y, mode; cin >> y >> x >> mode; // t = direction (0 = clockwise, 1 = anticlockwise)
        int cur = 1, t = 1;
        x--; y--;
        matrix[y][x] = cur; times[y][x] = t;
        int cnt = 0, temp = 1, dir = 0;
        while(true) {
            if(abs(x) >=2*m and abs(y)>= 2*n) break;
            t++;
            cur++;
            cnt++;
            //cout << x << " " << y << endl; //" " << cur << " " << cnt << " " << t << " " << dir;
            if(mode==0) {
                switch(dir) {
                    case 0: y--; break;
                    case 1: x++; break;
                    case 2: y++; break;
                    case 3: x--; break;
                }
                

                if(cnt/temp > 0 and cnt%temp==0) {
                    dir = (dir+1)%4;
                }
            }
            else {
                switch(dir) {
                    case 0: y--; break;
                    case 1: x--; break; 
                    case 2: y++; break;
                    case 3: x++; break;
                }


                if(cnt/temp > 0 and cnt%temp==0) {
                    dir = (dir+1)%4;
                }
            }

            if(cnt/temp == 2) {
                cnt = 0;
                temp++;
            }
            if(y>=0 and y < n and x >= 0 and x < m) {
                if(t<times[y][x] or times[y][x]==0) {
                    times[y][x] = t;
                    matrix[y][x] = cur;
                }
            }
        }
        //cout << endl << endl << endl;
    }

    for(auto &x: matrix) {
        for(auto &y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}