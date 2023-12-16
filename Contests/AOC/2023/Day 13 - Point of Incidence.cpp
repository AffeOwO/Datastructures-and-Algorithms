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
    
    ll sol1 = 0, sol2 = 0;
    string s;
    vector<vector<vector<char>>> matrices = {{}};

    // reading the input
    while(getline(fin, s)) {
        if(s.size()==0) {
            int n = matrices.back().size(), m = matrices.back()[0].size();
            bool refl;
            for(int i=0; i<n-1; i++) {
                refl = true;
                int cnt = 0;
                for(int k=0; i>=k and i+k+1<n; k++) {
                    if(matrices.back()[i-k]!=matrices.back()[i+k+1]) refl = false;
                    for(int j=0; j<m; j++) {
                        if(matrices.back()[i-k][j]!=matrices.back()[i+k+1][j]) cnt++;
                    }
                }
                if(refl) sol1 += 100*(i+1);
                if(cnt==1) {
                    sol2 += 100*(i+1);
                }
            }
            for(int j=0; j<m-1; j++) {
                refl = true;
                int cnt = 0;
                for(int k=0; j>=k and j+k+1<m; k++) {
                    // compare j-k th column with j+k+1 th column
                    for(int i=0; i<n; i++) {
                        if(matrices.back()[i][j-k] != matrices.back()[i][j+k+1]) {
                            refl = false;
                            cnt++;
                        }
                    }
                }
                if(refl) sol1 += (j+1);
                if(cnt==1) sol2 += (j+1);
            }
            matrices.push_back({});
        }
        else {
            matrices.back().push_back({});
            for(auto &x: s) matrices.back().back().push_back(x);
        }
    }


    fout << sol1 << endl << sol2 << endl;
}