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

double n, d;
vector<pair<pair<double, double>, bool>> people;

void infect(int cur) {
    for(int i=1; i<n; i++) {
        if(i==cur or people[i].second==true) continue;
        double dist = sqrt(pow(people[i].first.first-people[cur].first.first, 2) + pow(people[i].first.second-people[cur].first.second, 2));
        if(dist<=d) {
            people[i].second = true;
            infect(i);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> d;
    people.resize(n);
    people[0].second = true;
    cin >> people[0].first.first >> people[0].first.second;
    for(int i=1; i<n; i++) {
        cin >> people[i].first.first >> people[i].first.second;
        people[i].second = false;
    }
    // weighted graph do bfs
    infect(0);
    for(auto &x: people) {
        if(x.second == true) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}