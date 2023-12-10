#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // part 1
    // pipe containing the animal is a loop
    vector<vector<char>> system;
    string s; 
    int i=0;
    pair<int, int> prev, cur;
    while(getline(fin, s)) {
        system.push_back({});
        for(int j=0; j<s.size(); j++) {
            system.back().push_back(s[j]);
            if(s[j] == 'S') prev = make_pair(i, j);
        }
        i++;
    }
    int length = 1;
    cur = make_pair(prev.first-1, prev.second); // my input
    while('S' != system[cur.first][cur.second]) {
        length++;
        switch(system[cur.first][cur.second]) {
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
    }


    fout << length/2 << endl;
}