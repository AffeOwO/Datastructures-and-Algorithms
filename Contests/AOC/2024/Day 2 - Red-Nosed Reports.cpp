#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);

    // part 1
    int sol = 0;

    vector<vector<int>> idk;

    for(string line; getline(fin, line);) {
        vector<int> cur;
        istringstream x(line);
        int n;
        while(x>>n) {
            cur.push_back(n);
        }
        idk.push_back(cur);
        bool val = true, ord = (cur[0]<cur[1]);
        if(cur[0]==cur[1]) val = false;

        for(int i=1; i<cur.size(); i++) {
            if(ord==true and cur[i-1]>=cur[i]) val = false;
            if(ord==false and cur[i-1]<=cur[i]) val = false;
            if(abs(cur[i-1]-cur[i])>3) val = false;
            if(!val) break;
        }

        if(val) sol++;
    }   
    fout << sol << endl;

    // part 2
    int sol2 = 0;
    for(auto &x: idk) {
        for(int i=0; i<x.size(); i++) {
            vector<int> cur;
            for(int j=0; j<x.size(); j++) {
                if(i==j) continue;
                cur.push_back(x[j]);
            }
            bool val = true, ord = (cur[0]<cur[1]);
            if(cur[0]==cur[1]) val = false;

            for(int i=1; i<cur.size(); i++) {
                if(ord==true and cur[i-1]>=cur[i]) val = false;
                if(ord==false and cur[i-1]<=cur[i]) val = false;
                if(abs(cur[i-1]-cur[i])>3) val = false;
                if(!val) break;
            }
            if(val) {
                sol2++;
                break;
            }
        }
    }

    fout << sol2 << endl;
}