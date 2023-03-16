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

vector<pair<string, string>> rules;
vector<string> cows{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"}; 
int n;

bool checky(vector<string>& order) {
    for(int j=0; j<n; j++) {
        for(int i=0; i<8; i++) {
            if(order[i] == rules[j].first || order[i] == rules[j].second) {
                if(i==7) return false;
                if(order[i+1] == rules[j].first || order[i+1] == rules[j].second) break;
                return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    fin >> n;
    rules.resize(n);
    cows.resize(8);
    string idk;
    for(int i=0; i<n; i++) fin >> rules[i].first >> idk >> idk >> idk >> idk >> rules[i].second;
    // maybe O(n! * n^2 * logn) -> n<=8 -> < 10mio
    
    sort(cows.begin(), cows.end());
    vector<vector<string>> sol;
    do{
        if(checky(cows)) sol.push_back(cows);
    } while(next_permutation(cows.begin(), cows.end()));
    sort(begin(cows), end(cows));
    for(auto x: sol[0]) {
        fout << x << endl;
    }
}