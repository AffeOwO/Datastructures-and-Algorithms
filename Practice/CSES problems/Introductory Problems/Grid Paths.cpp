#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int p[48];
bool onPath[9][9];
int tryPath(int pathIdx, int curR, int curC);

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    getline(cin, line);

    for(int i=0; i<48; i++) {
        char cur = line[i];
        if(cur=='U') {
            p[i] = 0;
        }
        else if(cur=='R') {
            p[i] = 1;
        }
        else if(cur=='D') {
            p[i] = 2;
        }
        else if(cur=='L') {
            p[i] = 3;
        }
        else {
            p[i] = 4;
        }
    }

    for(int i=0; i<9; i++) {
        onPath[0][i] = true;
        onPath[8][i] = true;
        onPath[i][0] = true;
        onPath[i][8] = true;
    }

    for(int i=1; i<=7; i++) {
        for(int j=1; j<=7; j++) {
            onPath[i][j] = false;
        }
    }

    int ans = tryPath(0, 1, 1);
    cout << ans << endl;
}

int tryPath(int pathIdx, int curR, int curC) {
    if((onPath[curR][curC-1] && onPath[curR][curC+1]) && (!onPath[curR-1][curC] && !onPath[curR+1][curC])) {return 0;}
    if((!onPath[curR][curC-1] && !onPath[curR][curC+1]) && (onPath[curR-1][curC] && onPath[curR+1][curC])) {return 0;}

    if(curR==7 && curC==1) {
        if(pathIdx == 48) {
            return 1;
        }
        return 0;
    }
    if(pathIdx==48) {
        return 0;
    }

    int ret = 0;
    onPath[curR][curC] = true;

    if(p[pathIdx] < 4) {
        int nxtR = curR + dr[p[pathIdx]];
        int nxtC = curC + dc[p[pathIdx]];
        if(!onPath[nxtR][nxtC]) {
            ret += tryPath(pathIdx+1, nxtR, nxtC);
        }
    }
    else {
        for(int i=0; i<4; i++) {
            int nxtR = curR+dr[i];
            int nxtC = curC+dc[i];
            if(onPath[nxtR][nxtC]) {continue;}
            ret += tryPath(pathIdx+1, nxtR, nxtC);
        }
    }
    onPath[curR][curC] = false;
    return ret;
}