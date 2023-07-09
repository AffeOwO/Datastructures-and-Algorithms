#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n; // deck of 2n cards (n cards for each of the 2 players); cards numbered from 1->2n
    // in each of the n rounds bessie, elsie both play a single card
    // first n/2 rounds -> player with highest card wins a point; last n/2 rounds -> player with lowest card wins a point
    // output the maximum number of points bessie can get
    // elsies turns are predictable
    pair<vector<int>, vector<int>> elsie;
    vector<int> bessie;
    vector<bool> cards(2*n);
    for(int i=0; i<n; i++) {
        int cur; fin >> cur;
        cards[cur-1] = true;
        if(i<n/2) elsie.first.push_back(cur);
        else elsie.second.push_back(cur);
    }
    sort(all(elsie.first)); sort(all(elsie.second), greater<int>());
    for(int i=0; i<2*n; i++) {
        if(!cards[i]) bessie.push_back(i+1);
    }
    sort(all(bessie)); // use bessie n/2 first cards for second round; last n/2 cards for first round
    int sol = 0;
    // 2 pointer
    // for(auto &x: elsie.second) cout << x << endl;
    int pnt = n/2;
    for(auto &x: elsie.first) {
        while(pnt<n and x>bessie[pnt]) pnt++;
        if(pnt == n) break;
        sol++;
        pnt++;
    }
    pnt = 0;
    sort(bessie.begin(), bessie.begin()+n/2, greater<int>());
    //for(auto &x: bessie) cout << x << endl;
    for(auto &x: elsie.second) {
        while(pnt<n/2 and x<bessie[pnt]) pnt++;
        if(pnt == n/2) break;
        sol++;
        pnt++;
    }

    fout << sol << endl;
}