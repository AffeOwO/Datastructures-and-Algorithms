/*
ID: yamato berner (affeowo1)
TASK: combo
LANG: C++23
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<int> john(3), master(3);
    for(auto &x: john) fin >> x;
    for(auto &x: master) fin >> x;

    int sol = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                // just check lol 
                // too tired to do this easy thing rn
                vector<int> diff_j, diff_m;
                diff_j.push_back(abs(john[0]-i));
                diff_j.push_back(abs(john[1]-j));
                diff_j.push_back(abs(john[2]-k));
                diff_m.push_back(abs(master[0]-i));
                diff_m.push_back(abs(master[1]-j));
                diff_m.push_back(abs(master[2]-k));

                if(((diff_j[0]<=2 or diff_j[0]>=n-2) and (diff_j[1]<=2 or diff_j[1]>=n-2) and (diff_j[2]<=2 or diff_j[2]>=n-2)) or 
                    ((diff_m[0]<=2 or diff_m[0]>=n-2) and (diff_m[1]<=2 or diff_m[1]>=n-2) and (diff_m[2]<=2 or diff_m[2]>=n-2))
                ) {sol++;}
            }
        }
    }
    fout << sol << endl;
}