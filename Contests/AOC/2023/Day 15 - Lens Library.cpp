#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, cur; getline(fin, s);
    ll sol1 = 0, sol2 = 0;
    stringstream ss(s); 
    vector<vector<pair<string, int>>> boxes(256);
    while(getline(ss, cur, ',')) {
        ll temp = 0, label_hash;
        for(auto &x: cur) {
            if(x=='=' or x=='-') label_hash = temp;
            temp = ((temp+(int)x)*17)%256;
        }
        sol1 += temp;
        if(cur[cur.size()-2]=='=') {
            bool idk = true;
            for(auto &x: boxes[label_hash]) {
                if(x.first==cur.substr(0, cur.size()-2)) {
                    idk = false;
                    x.second = cur.back()-'0';
                    break;
                }
            }
            if(idk) {
                boxes[label_hash].push_back(make_pair(cur.substr(0, cur.size()-2), cur.back()-'0'));
            }
        }
        else {
            for(int i=0; i<boxes[label_hash].size(); i++) {
                if(boxes[label_hash][i].first==cur.substr(0, cur.size()-1)) {
                    for(int k=i; k<boxes[label_hash].size()-1; k++) boxes[label_hash][k] = boxes[label_hash][k+1];
                    boxes[label_hash].pop_back();
                    break;
                }
            }
        }
    }
    for(int i=0; i<256; i++) {
        for(int j=0; j<boxes[i].size(); j++) {
            sol2 += (i+1)*(j+1)*boxes[i][j].second;
        }
    }

    fout << sol1 << endl << sol2 << endl;
}