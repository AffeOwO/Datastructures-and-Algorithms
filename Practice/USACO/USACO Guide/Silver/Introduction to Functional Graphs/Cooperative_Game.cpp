#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int query(vector<int> move) {
    cout << "next ";
    for(auto &x: move) cout << x << " ";
    cout << endl << flush;
    int res;
    string trash;
    cin >> res;
    for(int i=0; i<res; i++) cin >> trash;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 0-indexed (0-9) (10 players, misha doesnt play)
    // all ten people atart at the home vertex
    // max q queries
    /* interactions:
    - move people -> "next p1 p2 ... pn"
    - finish -> "done"
    */
    /*
    after each query, misha will say the ids of players who are on the same node
    */
    /*
    approach #1:
    - floyds algorithm: first do a fast and slow player and move them until they meet again
    - then send the rest and the other two players like the slow pointer
    - amount of operations: 3t+c? // will prolly work
    */
    // how to implement this now?
    // what about t == 1 or c == 1?

    while(true) {
        // 0 = fast pnt; 1 = slow pnt
        query({0, 1});
        int temp = query({0});
        if(temp==2) break;
    }
    while(true) {
        int temp = query({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        if(temp == 1) break;
    }
    cout << "done" << endl << flush;
}