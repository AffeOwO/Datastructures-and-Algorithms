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
#define MOD (ll)1000000007;

const vector<string> signs{"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

struct Relation {
    string name;
    bool prev;
    int year;
    string relative;
};

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<Relation> relations(n);
    for(Relation &r : relations) {
        string t, prev, sign;
        cin >> r.name >> t >> t >> prev >> sign >> t >> t >> r.relative;
        r.prev = prev == "previous";
        r.year = find(all(signs), sign) - signs.begin();
    }
    unordered_map<string, int> hashy {{"Bessie", 0}};
    for(Relation r: relations) {
        int change = r.prev ? -1 : 1;
        int year = hashy[r.relative] + change;
        while(((year % 12) + 12 ) % 12 != r.year) year += change;
        hashy[r.name] = year;
    }
    cout << abs(hashy["Bessie"] - hashy["Elsie"]) << endl;
    
    // bessie is born in a year of an ox
    // cycle all 12 years 
}