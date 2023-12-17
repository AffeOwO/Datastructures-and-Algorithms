#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, m;

void rotate(vector<vector<char>> &mat) {
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            if(mat[i][j]=='O') {
                mat[i][j] = '.';
                for(int k=i; k>=0; k--) {
                    if(k==0) mat[k][j] = 'O';
                    else if(mat[k-1][j]!='.') {
                        mat[k][j] = 'O';
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j]=='O') {
                mat[i][j] = '.';
                for(int k=j; k>=0; k--) {
                    if(k==0) mat[i][k] = 'O';
                    else if(mat[i][k-1]!='.') {
                        mat[i][k] = 'O';
                        break;
                    }
                }
            }
        }
    }
    for(int j=0; j<m; j++) {
        for(int i=n-1; i>=0; i--) {
            if(mat[i][j]=='O') {
                mat[i][j] = '.';
                for(int k=i; k<n; k++) {
                    if(k==n-1) mat[k][j] = 'O';
                    else if(mat[k+1][j]!='.') {
                        mat[k][j] = 'O';
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=m-1; j>=0; j--) {
            if(mat[i][j]=='O') {
                mat[i][j] = '.';
                for(int k=j; k<m; k++) {
                    if(k==m-1) mat[i][k] = 'O';
                    else if(mat[i][k+1]!='.') {
                        mat[i][k]='O';
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);

    // part 1
    ll sol1 = 0;
    vector<vector<char>> matrix;
    string s;
    while(getline(fin, s)) {
        matrix.push_back({});
        for(auto &x: s) matrix.back().push_back(x);
    }
    n = matrix.size(); m = matrix[0].size();

    for(int j=0; j<m; j++) {
        int last = 0;
        for(int i=0; i<n; i++) {
            if(matrix[i][j]=='O') {
                sol1 += (n-last);
                last++;
            }
            else if(matrix[i][j]=='#') last = i+1;
        }
    }
    fout << sol1 << endl;   

    // part 2
    // simulate, find pattern, mod  
    ll sol2 = 0;
    map<vector<vector<char>>, ll> hashy = {{matrix, 0}}; 

    ll idk = 1000000000;
    for(int i=1; i<=idk; i++) {
        rotate(matrix);
        
        if(hashy.count(matrix)) {
            ll cyc_len = i-hashy[matrix]; ll temp = (idk-i)%cyc_len;
            for(auto &x: hashy) {
                if(hashy[matrix]+temp==x.second) {
                    matrix = x.first;
                    break;
                }
            }


            for(int ii=0; ii<n; ii++) {
                for(int j=0; j<m; j++) {
                    if(matrix[ii][j]=='O') sol2 += (n-ii);
                }
            }
            break;
        }
        hashy[matrix] = i;
    }
    fout << sol2 << endl;
}