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

int n; 
string a, b; 
map<string, string> parent;
pair<vector<string>, vector<string>> ancestor; // .first = a; .second = b

void find_anc(string s, bool temp) {
    while(parent.count(s)) {
        s = parent[s];
        if(temp) {
            ancestor.first.push_back(s);
        }
        else {
            ancestor.second.push_back(s);
        }
    }
}

int main() {
    ifstream fin("family.in");
    ofstream fout("family.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fin >> n;
    fin >> a >> b;    
    
    for(int i=0; i<n; i++) {
        string x, y; fin >> x >> y;
        parent[y] = x;
    }
    find_anc(a, true); find_anc(b, false);

    bool idk = false;
    bool not_rel = false;
    for(int i=0; i<ancestor.first.size(); i++) {
        for(int j=0; j<ancestor.second.size(); j++) {
            if(ancestor.first[i] == ancestor.second[j]) {
                idk = true;
                int m = ancestor.first.size() - i - 1;
                for(int k=0; k<m; k++) ancestor.first.pop_back();
                m = ancestor.second.size() - j - 1;
                for(int k=0; k<m; k++) ancestor.second.pop_back();
                break;
            }
            if(i==ancestor.first.size()-1 and j==ancestor.second.size()-1) not_rel = true;
        }
        if(idk) break;
    }
    if(ancestor.first.size() == 0) {
        int cnt = 0;
        for(auto &x: ancestor.second) {
            if(x==a) cnt++;
        }
        if(cnt == 0) not_rel = true;
    }
    if(ancestor.second.size() == 0) {
        int cnt = 0;
        for(auto &x: ancestor.first) {
            if(x==b) cnt++;
        }
        if(cnt == 0) not_rel = true;
    }

    if(not_rel) fout << "NOT RELATED" << endl;
    else if(ancestor.first.size()!=0 and ancestor.second.size()==0) {
        fout << b << " is the ";
        for(int i=2; i<ancestor.first.size(); i++) fout << "great-";
        if(ancestor.first.size()!=1) fout << "grand-";
        fout << "mother of " << a;
    }
    else if(ancestor.second.size()!=0 and ancestor.first.size()==0) {
        fout << a << " is the ";
        for(int i=2; i<ancestor.second.size(); i++) fout << "great-";
        if(ancestor.second.size()!=1) fout << "grand-";
        fout << "mother of " << b;
    }
    else if(ancestor.first.size()>ancestor.second.size() and ancestor.second.size()==1) {
        fout << b << " is the ";
        for(int i=2; i<ancestor.first.size(); i++) fout << "great-";
        fout << "aunt of " << a;
    }
    else if(ancestor.second.size()>ancestor.first.size() and ancestor.first.size()==1){
        fout << a << " is the ";
        for(int i=2; i<ancestor.second.size(); i++) fout << "great-";
        fout << "aunt of " << b;
    }
    else {
        if(ancestor.first.size()==1) fout << "SIBLINGS" << endl;
        else fout << "COUSINS" << endl;
    }
    

    
    for(auto &x: ancestor.first) cout << x << " ";
    cout << endl;
    for(auto &x: ancestor.second) cout << x << " "; 
    
}