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
    ifstream fin("evolution.in");
    ofstream fout("evolution.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    
<<<<<<< HEAD
    for(int i=0; i<n; i++) {
        int idk; fin >> idk;
        for(int j=0; j<idk; j++) {
            string s; fin >> s;
            
        }
    }

=======
    vector<set<string>> nodes(n);
    set<string> characteristics_t;
    for(int i=0; i<n; i++) {
        int features; fin >> features;
        for(int j=0; j<features; j++) {
            string s; fin >> s;
            nodes[i].insert(s);
            characteristics_t.insert(s);
        }
    }
    vector<string> characteristics(all(characteristics_t));
    int m = characteristics.size();
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            bool both = false, only_a = false, only_b = false;
            for(auto &x: nodes) {
                bool has_a = x.count(characteristics[i]);
                bool has_b = x.count(characteristics[j]);

                if(has_a and has_b) both = true;
                else if(has_a) only_a = true;
                else if(has_b) only_b = true;
            }
            if(only_a and only_b and both) {
                fout << "no" << endl;
                return 0;
            }
        }
    }
    fout << "yes" << endl;
    // only one subpop with no features
    // if xy and x, then xy and x have the same parent node
    // if all cows have a feature, then ancestor didnt split 
    // if more cows have feature x than feature y and one cow has both, then x is above y somewhere
>>>>>>> 9688c41 (yay)
}