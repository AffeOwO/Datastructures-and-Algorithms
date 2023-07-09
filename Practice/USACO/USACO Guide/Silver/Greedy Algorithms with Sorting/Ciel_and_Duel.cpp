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
    
    int n, m; cin >> n >> m; // jiro and ciels cards
    pair<vector<int>, vector<int>> jiro; // .first = attack; .second = defense
    vector<int> ciel(m);
    for(int i=0; i<n; i++) {
        string s; int cur; cin >> s >> cur;
        if(s=="ATK") jiro.first.push_back(cur);
        else jiro.second.push_back(cur+1); // to avoid different cases and make both conditions >=
    }
    for(auto &x: ciel) cin >> x;
    sort(all(jiro.first)); sort(all(jiro.second)); // now for both >=
    sort(all(ciel));
    
    
    /*
    todo:
    - check condition for cases (done)

    2 cases:
    - we can destroy all of jiros cards:

    - we cant:
    - greedily attack jiros def cards only (done)
    */


    bool possible = false;
    if(m>n) { 
        // if n<=m -> we wont ever attack jiro with him having no cards
        int pnt1 = 0, pnt2 = 0;
        for(int i=0; i<m; i++) {
            if(pnt1 != jiro.first.size() and pnt2 != jiro.second.size()) {
                if(ciel[i]>=jiro.first[pnt1] and ciel[i]>=jiro.second[pnt2]) {
                    if(jiro.first[pnt1]<jiro.second[pnt2]) pnt1++;
                    else pnt2++;
                }
                else if(ciel[i]>=jiro.first[pnt1]) pnt1++;
                else if(ciel[i]>=jiro.second[pnt2]) pnt2++;
            }
            else if(pnt1 != jiro.first.size()) {
                if(ciel[i]>=jiro.first[pnt1]) pnt1++;
            }
            else if(pnt2 != jiro.second.size()) {
                if(ciel[i]>=jiro.second[pnt2]) pnt2++;
            }
            else {
                possible = true;
                break;
            }
        }
    }
    
    int sol = 0, idk = 0;

    int pnt = m-1;
    for(auto &x: jiro.first) {
        if(x>ciel[pnt])  continue;
        sol += (ciel[pnt]-x);
        pnt--;
        if(pnt == -1) break;
    }
    
    if(possible) {
        // go for defeating all of jiros cards (idk)
        // first destroy all DEF cards
        pnt = 0;
        vector<bool> used(m);
        for(auto &x: jiro.second) {
            while(ciel[pnt]<x or used[pnt]) pnt++;
            used[pnt] = true;
        }
        for(auto &x: jiro.first) idk -= x;
        for(int i=0; i<m; i++) {
            if(!used[i]) idk += ciel[i];
        }
    }

    
    cout << max(sol, idk) << endl;
}

// if(pnt1 == jiro.first.size() and pnt2 == jiro.second.size())

/*
if(m<=jiro.first.size() or jiro.second.size()==0) {
        // attack lowest with highest and so on
        int pnt = 0;
        for(int i=m-1; i>=0; i--) {
            if(ciel[i]>jiro.first[pnt]) sol += (ciel[i]-jiro.first[pnt]);
            pnt++;
            if(pnt==jiro.first.size()) break;
        }
    }
    else {
        // else ?
        
    }


// check if you will ever have to attack DEF cards?
    bool pos = true;
    vector<int> idk = ciel;
    for(int i=0; i<jiro.first.size(); i++) {
        if(ciel.size() == 0 or jiro.first[i]>ciel.back()) {
            pos = false;
            continue;
        }
        sol += (ciel.back()-jiro.first[i]);
        ciel.pop_back();
    }

    if(pos and n<m and jiro.second.size() != 0) {
        ciel = idk; // sol = 0; ???
        // all ATT cards can be destroyed and it could be possible that all DEF could also be destroyed (could also not be the case)
        
        
    }
*/