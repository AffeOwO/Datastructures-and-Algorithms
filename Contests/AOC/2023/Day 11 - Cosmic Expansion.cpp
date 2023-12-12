#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int n, m;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<char>> image;
    vector<pair<int, int>> galaxies;
    string s;
    while(getline(fin, s)) {
        image.push_back({});
        for(auto &x: s) {
            image.back().push_back(x);
            if(x=='#') galaxies.push_back(make_pair(image.size()-1, image.back().size()-1));
        }
    }
    n = image.size(); m = image[0].size();
    pair<vector<int>, vector<int>> pref; // .first = horizontal, .second = vertical
    pref.first.resize(n+1); pref.second.resize(m+1);

    
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<m; j++) cnt += (image[i][j]=='#');
        pref.first[i+1] = pref.first[i];
        if(cnt==0) pref.first[i+1]++;
        //cout << pref.first[i+1] << " ";
    }
    //cout << endl;
    for(int j=0; j<m; j++) {
        int cnt = 0;
        for(int i=0; i<n; i++) cnt += (image[i][j]=='#');
        pref.second[j+1] = pref.second[j];
        if(cnt==0) pref.second[j+1]++;
        //cout << pref.second[j+1] << " ";
    }
    //cout << endl;

    ll sol1 = 0, sol2 = 0;
    for(int i=0; i<galaxies.size(); i++) {
        for(int j=i+1; j<galaxies.size(); j++) {
            ll dist = abs(galaxies[i].first-galaxies[j].first) + abs(galaxies[i].second-galaxies[j].second);
            ll addi = abs(pref.first[galaxies[i].first]-pref.first[galaxies[j].first]);
            addi += abs(pref.second[galaxies[i].second]-pref.second[galaxies[j].second]);
            sol1 += dist + addi; sol2 += dist+((ll)999999*addi);
        }
    }

    fout << sol1 << endl << sol2 << endl;;
}