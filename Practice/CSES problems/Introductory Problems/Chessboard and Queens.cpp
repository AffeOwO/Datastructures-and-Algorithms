#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

vector<bool> diag1(30);
vector<bool> diag2(30);
vector<bool> placed(30);
vector<vector<bool>> placed2(8, vector<bool>(8));
vector<vector<char>> arr;
int sol;
void solve(int cur) {
    if(cur==8) {
        sol++;
        return;
    }

    for(int r=0; r<8; r++) {
        if(arr[r][cur] == '.' && diag1[r-cur+7] == false && diag2[r+cur] == false && placed[r] == false) {
            placed2[r][cur] = true;
            diag1[r-cur+7] = diag2[r+cur] = placed[r] = true;
            solve(cur+1);
            placed2[r][cur] = false;
            diag1[r-cur+7] = diag2[r+cur] = placed[r] = false;
        }
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    arr = vector<vector<char>>(8);
    sol = 0;
    for(int i=0; i<8; i++) {
        arr[i] = vector<char>(8);
        for(int j=0; j<8; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0);
    cout << sol << endl;
}