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
    
    // part 1
    map<string, pair<string, string>> hashy;
    string inst; getline(fin, inst);
    string cur; getline(fin, cur);
    while(getline(fin, cur)) {
        hashy[cur.substr(0, 3)] = make_pair(cur.substr(7, 3), cur.substr(12, 3));
    }
    int sol1 = 0, n = inst.size();
    cur = "AAA";
    while(cur!="ZZZ") {
        if(inst[sol1%n]=='L') cur = hashy[cur].first;
        else cur = hashy[cur].second;
        sol1++;
    }

    fout << sol1 << endl;

    // part 2 
    vector<string> nodes;
    for(auto &x: hashy) {
        if(x.first[2]=='A') nodes.push_back(x.first);
    }
    ll sol2 = 1;

    for(auto &x: nodes) {
        string temp = x;
        ll temp_cnt = 0;
        while(temp[2]!='Z') {
            if(inst[temp_cnt%n]=='L') temp = hashy[temp].first;
            else temp = hashy[temp].second;
            temp_cnt++;
        }
        fout << temp_cnt << endl;
    }

    // compute sol (lcm of nums) in python due to too big nums
}