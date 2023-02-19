#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string inp;
    cin >> inp;

    string upper_ver = "", lower_ver = "";

    int lower = 0, upper = 0;
    for(int i=0; i<size(inp); i++) {
        if(isupper(inp[i])) {
            upper += 1;
        }
        else {
            lower += 1;
        }
        upper_ver.push_back(toupper(inp[i]));
        lower_ver.push_back(tolower(inp[i]));
    }

    if(upper > lower) {
        cout << upper_ver;
    }
    else {
        cout << lower_ver;
    }
}