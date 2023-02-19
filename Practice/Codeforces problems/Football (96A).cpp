#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string players;
    cin >> players;
    bool found = false;
    if(size(players) > 7) {
        for(int i=0; i<size(players)-6; i++) {
            if(players.substr(i, 7) == "1111111" || players.substr(i, 7) == "0000000") {
                found = true;
            }
        }
    } 


    if(found == true) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    
}