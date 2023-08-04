#include <bits/stdc++.h>

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
    
    int n, m; cin >> n >> m;
    pair<int, int> A, B;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<m; j++) {
            matrix[i][j] = s[j];
            if(s[j] == 'A') A = make_pair(i, j);
            else if(s[j] == 'B') B = make_pair(i, j);
        }
    }
    // . = floor; # = wall; A = start; B = end
    vector<vector<char>> prev(n, vector<char>(m, 'N')); prev[A.first][A.second] = 'A';
    queue<pair<int, int>> q; q.push(make_pair(A.first, A.second)); 
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if(cur.first>0 and prev[cur.first-1][cur.second] == 'N' and matrix[cur.first-1][cur.second] != '#') {
            q.push(make_pair(cur.first-1, cur.second));
            prev[cur.first-1][cur.second] = 'U';
        }
        if(cur.first<n-1 and prev[cur.first+1][cur.second] == 'N' and matrix[cur.first+1][cur.second] != '#') {
            q.push(make_pair(cur.first+1, cur.second));
            prev[cur.first+1][cur.second] = 'D';
        }
        if(cur.second>0 and prev[cur.first][cur.second-1] == 'N' and matrix[cur.first][cur.second-1] != '#') {
            q.push(make_pair(cur.first, cur.second-1));
            prev[cur.first][cur.second-1] = 'L';
        }
        if(cur.second<m-1 and prev[cur.first][cur.second+1] == 'N' and matrix[cur.first][cur.second+1] != '#') {
            q.push(make_pair(cur.first, cur.second+1));
            prev[cur.first][cur.second+1] = 'R';
        }
        //cout << cur.first << " " << cur.second << endl;
    }

    if(prev[B.first][B.second] == 'N') cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        vector<char> sol;
        int cy = B.first, cx = B.second;
        char cur = prev[cy][cx];
        while(cur != 'A') {
            sol.push_back(cur);
            switch(cur) {
                case 'U':
                    cy++;
                    break;
                case 'D':
                    cy--;
                    break;
                case 'L':
                    cx++;
                    break;
                case 'R':
                    cx--;
                    break;
            }
            cur = prev[cy][cx];
        }
        cout << sol.size() << endl;
        for(int i=sol.size()-1; i>=0; i--) cout << sol[i];
        cout << endl;
    }
}