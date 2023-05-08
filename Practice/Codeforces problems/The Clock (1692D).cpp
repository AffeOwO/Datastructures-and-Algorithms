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

void solve() {
    string time; cin >> time;
    int interval; cin >> interval;
    pair<int, int> intervaly;
    intervaly.first = interval/60;
    intervaly.second = interval%60;
    pair<int, int> clock;
    clock.first = (time[0]-'0')*10 + time[1]-'0';
    clock.second = (time[3]-'0')*10 + time[4]-'0';
    
    int sol = 0;
    if(clock.first == (clock.second%10*10+clock.second/10)) sol++;
    pair<int, int> start = clock;
    while(true) {
        clock.second += intervaly.second;
        if(clock.second >= 60) {
            clock.first += 1;
            clock.second %= 60;
        }
        clock.first = (clock.first + intervaly.first) % 24;
        if(start == clock) break;
        if(clock.first == (clock.second%10*10+clock.second/10)) sol++;
    }
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}