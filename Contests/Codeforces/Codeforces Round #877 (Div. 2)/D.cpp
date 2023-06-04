#include <bits/stdc++.h>

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
    
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<char> idk(n);
    for(int i=0; i<n; i++) idk[i] = s[i];

    pair<int, int> doubles; // .first = (, .second = )
    for(int i=0; i<n-1; i++) {
        if(s[i]==s[i+1]=='(') doubles.first++;
        else if(s[i]==s[i+1]==')') doubles.second++;
    }
    pair<int, int> cnt{0, 0};
    for(auto &x: idk) {
        if(x=='(') cnt.first++;
        else cnt.second++;
    }

    while(q--) {
        int ind; cin >> ind;
        if(ind!=1 and idk[ind-1] == idk[ind-2]) {
            if(idk[ind-1] == ')') doubles.second--;
            else doubles.first--;
        }
        else if(ind !=n and idk[ind-1] == idk[ind]) {
            if(idk[ind-1] == ')') doubles.second--;
            else doubles.first--;
        }
        if(idk[ind+1] == ')') {
            idk[ind+1] = '(';
            cnt.first++;
            cnt.second--;
        }
        else {
            idk[ind+1] = ')';
            cnt.first--;
            cnt.second++;
        }
        // if (( and )), then its  walkable
        // if first = ) or last = (, then no
        if(idk[0] == ')' or idk[n-1] == '(') cout << "No" << endl;
        else if(doubles.first>0 and doubles.second>0) cout << "Yes" << endl;
        
    }
}