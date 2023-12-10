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
    
    // part 1 & 2
    vector<vector<int>> vals;
    string s;
    ll sol1 = 0, sol2 = 0;
    while(getline(fin, s)) {
        stringstream ss(s);
        vals.push_back({});
        while(getline(ss, s, ' ')) {
            vals.back().push_back(stoi(s));
        }
        vector<vector<int>> diffs;
        diffs.push_back(vals.back());
        int cnt = 0, len = diffs[0].size();
        while(cnt!=len and len!=1) {
            len--; cnt = 0;
            vector<int> cur;
            for(int i=0; i<len; i++) {
                cur.push_back(diffs.back()[i+1]-diffs.back()[i]);
                if(cur.back()==0) cnt++;
            }
            diffs.push_back(cur);
        }
        int temp1 = 0, temp2 = 0;
        for(int i=diffs.size()-1; i>=0; i--) {
            temp1 = temp1 + diffs[i].back();
            temp2 = diffs[i][0] - temp2;
        }
        sol1+=temp1; sol2+=temp2;
    }
    fout << sol1 << endl << sol2 << endl;
}