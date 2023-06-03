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
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int, string>> people(n);
    int youngest, cur = pow(10, 9)+1;
    for(int i=0; i<n; i++) {
        cin >> people[i].second >> people[i].first;
        if(people[i].first<cur) {
            cur = people[i].first;
            youngest = i;
        }
    }
    for(int i=youngest; i<youngest+n; i++) {
        cout << people[i%n].second << endl;
    }
    
}