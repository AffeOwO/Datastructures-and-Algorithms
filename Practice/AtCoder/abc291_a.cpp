#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    for(int i=0; i<size(s); i++) {
        if(isupper(s[i])) {
            cout << i+1 << endl;
            break;
        }
    }
}