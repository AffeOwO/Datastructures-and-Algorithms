#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<bool>> visited;
vector<vector<char>> systemy, pipe;

void floody1(int y, int x) {
    visited[y][x] = true;
    if(y>0 and !visited[y-1][x] and pipe[y-1][x] == '#') floody1(y-1, x);
    if(y<139 and !visited[y+1][x] and pipe[y+1][x] == '#') floody1(y+1, x);
    if(x>0 and !visited[y][x-1] and pipe[y][x-1] == '#') floody1(y, x-1);
    if(x<139 and !visited[y][x+1] and pipe[y][x+1] == '#') floody1(y, x+1);
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // part 1&2
    // pipe containing the animal is a loop
    string s;
    int i=0;
    pair<int, int> prev, cur;
    while(getline(fin, s)) {
        systemy.push_back({});
        for(int j=0; j<s.size(); j++) {
            systemy.back().push_back(s[j]);
            if(s[j] == 'S') prev = make_pair(i, j);
        }
        i++;
    }
    pipe.resize(140, vector<char>(140, '#'));
    int length = 1;
    cur = make_pair(prev.first-1, prev.second); // my input
    while('S' != systemy[cur.first][cur.second]) {
        length++;
        switch(systemy[cur.first][cur.second]) {
            case '-':
                if(prev.second<cur.second) {
                    cur.second++;
                    prev.second++;
                }
                else {
                    cur.second--;
                    prev.second--;
                }
                break;
            case '|':
                if(prev.first<cur.first){
                    prev.first++;
                    cur.first++;
                }
                else {
                    prev.first--;
                    cur.first--;
                }
                break;
            case 'L':
                if(prev.first<cur.first) {
                    prev.first++;
                    cur.second++;
                }
                else {
                    prev.second--;
                    cur.first--;
                }
                break;
            case 'J':
                if(prev.first<cur.first) {
                    prev.first++;
                    cur.second--;
                }
                else {
                    cur.first--;
                    prev.second++;
                }
                break;
            case '7':
                if(prev.first>cur.first) {
                    prev.first--;
                    cur.second--;
                }
                else {
                    cur.first++;
                    prev.second++;
                }
                break;
            case 'F':
                if(prev.first>cur.first) {
                    prev.first--;
                    cur.second++;
                }
                else {
                    cur.first++;
                    prev.second--;
                }
                break;
        }
        pipe[prev.first][prev.second] = systemy[prev.first][prev.second];
    }
    visited.resize(140, vector<bool>(140));
    floody1(0, 0); floody1(139, 0); floody1(65, 0);

    /*
    for(auto x: visited) {
        for(auto y: x) fout << y;
        fout << endl;
    }
    for(auto x: pipe) {
        for(auto y: x) fout << y;
        fout << endl;
    }*/
    int sol2 = 0;
    for(int i=0; i<140; i++) {
        for(int j=0; j<140; j++) {
            if(!visited[i][j] and systemy[i][j] == '.') {
                int cnt = 0;
                for(int k=j+1; k<140; k++) {

                }

                if(cnt%2==1) sol2++:
            }
        }
    }
    
    fout << length/2 << endl << sol2 << endl;
}