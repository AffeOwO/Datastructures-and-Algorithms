#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

/*
struct req{
    int u, v, y;
};*/

ll n, m;
vector<vector<pair<ll, ll>>> edges; // .first = other node, .second = weigth
bool temp = true; // node n isnt in the same component as node 1
vector<bool> visited;

void check_1n(ll node) {
    if(visited[node]) return;
    visited[node] = true;
    if(node == n-1) temp = false;
    if(visited[n-1]) return;
    for(auto &x: edges[node]) check_1n(x.first);
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m; // n animal friends
    /*
    games (at most n²):
    choose some friends to play a game for t minutes
    - friend 1 has to play
    - friend n wont play
    - m additional reqs:
        - u, v, y; total time played of (u and not v) or (v and not u) <= y
    */
    //vector<req> additional(m);
    //for(auto &x: additional) cin >> x.u >> x.v >> x.y;
    // graph where y is the weight of edge between u and v and u + v < weight between u and v
    edges.resize(n);
    // bool edge_case = false;
    for(int i=0; i<m; i++) {
        ll u, v, y; cin >> u >> v >> y;
        // if u == n or v == n, then y = max time of the other player
        u--; v--;
        // if((u==n-1 or v==n-1) and y == 0) edge_case = true;
        edges[u].push_back({v, y});
        edges[v].push_back({u, y});
    }
    visited.resize(n);
    check_1n(0);
    if(temp) cout << "inf" << endl; // component without n can play infinite games
    else {
        int cnt = n-1;
        vector<bool> still_playing(n, true);
        vector<pair<string, ll>> games; // .first = players, .second = duration
        still_playing[n-1] = false;
        while(cnt>0 and still_playing[0]) {
            string cur = "";
            vector<ll> temp69;
            pair<ll, vector<ll>> curtime = {1e9, temp69}; // .first = time
            for(int i=0; i<n; i++) {
                if(still_playing[i]) {
                    cur += "1";
                    for(auto &x: edges[i]) {
                        if(!still_playing[x.first]) {
                            if(x.second<curtime.first) curtime = {x.second, {i}};
                            else if(x.second == curtime.first) curtime.second.push_back(i);
                        }
                    }
                }
                else cur += "0";
            }
            for(int i=0; i<n; i++) {
                if(!still_playing[i]) {
                    for(auto &x: edges[i]) {
                        if(still_playing[x.first]) x.second -= curtime.first;
                    }
                }
            }
            cnt -= curtime.second.size();
            for(auto &x: curtime.second) {
                still_playing[x] = false;
                for(auto &y: edges[x]) {
                    if(y.second <= 0) still_playing[y.first] = false;
                }
            }
            if(curtime.first == 0) continue;
            games.push_back({cur, curtime.first});
        }
        ll time_played = 0;
        for(auto &x: games) time_played += (ll)x.second;
        cout << time_played << " " << games.size() << endl;
        for(auto &x: games) cout << x.first << " " << x.second << endl;
    }
}