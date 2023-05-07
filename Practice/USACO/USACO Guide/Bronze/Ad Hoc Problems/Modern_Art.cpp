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
    ifstream fin("art.in");
    ofstream fout("art.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // looked at editorial since i wasnt able to solve this after multiple hours
    const int MAX_COLOR = 9;
    vector<int> right(MAX_COLOR+1), left(MAX_COLOR+1), up(MAX_COLOR+1), down(MAX_COLOR+1);
    for(int c=1; c<=MAX_COLOR; c++) {
        left[c] = up[c] = INT32_MAX;
        right[c] = down[c] = -1;
    }

    vector<bool> valid_start(MAX_COLOR+1);
    int width; fin >> width;
    vector<vector<int>> art(width, vector<int> (width));
    for(int r=0; r<width; r++) {
        for(int c=0; c<width; c++) {
            char curr_char; fin >> curr_char;
            int curr = curr_char - '0';
            art[r][c] = curr;
            if(curr!=0) {
                left[curr] = min(left[curr], c);
                right[curr] = max(right[curr], c);
                down[curr] = max(down[curr], r);
                up[curr] = min(up[curr], r);
                valid_start[curr] = true;
            }
        }
    }
    for(int color = 1; color<=MAX_COLOR; color++) {
        for(int r=up[color]; r<=down[color]; r++) {
            for(int c=left[color]; c<=right[color]; c++) {
                if(art[r][c] != color) valid_start[art[r][c]] = false;
            }
        }
    }
    int sol = 0;
    for(bool s: valid_start) sol += s;
    fout << sol << endl;
}