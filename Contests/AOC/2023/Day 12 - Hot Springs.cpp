#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll sol1 = 0;
// f_index = record.first index; s_index = record.second index
void solve1(pair<string, vector<ll>> record, int f_index, int s_index) {
    if(f_index + record.second[s_index] > record.first.size() 
    or (f_index>0 and record.first[f_index-1]=='#')) return;

    bool pos = true;
    for(int i=f_index; i<f_index+record.second[s_index]; i++) {
        if(record.first[i] == '.') pos = false;
    }
    // cout << f_index << " " << s_index << " " << pos << endl;

    if(pos) {
        if(s_index==record.second.size()-1) {
            int cnt = 0;
            for(int i=f_index+record.second[s_index]; i<record.first.size(); i++) cnt += (record.first[i]=='#');
            if(cnt==0) sol1++;
        }
        else solve1(record, f_index+1+record.second[s_index], s_index+1);
    }
    solve1(record, f_index+1, s_index);
}

map<pair<pair<ll, ll>, ll>, ll> dp;

ll solve2(pair<string, vector<ll>> record, ll f_index, ll s_index, ll cur) {
    pair<pair<ll, ll>, ll> temp = {{f_index, s_index}, cur};
    if(dp.count(temp)) return dp[temp];
    if(f_index==record.first.size()) {
        if(s_index==record.second.size() and cur == 0) return 1;
        else if(s_index==record.second.size()-1 and cur == record.second[s_index]) return 1;
        else return 0;
    }
    ll sol = 0;
    for(auto &x: {'.', '#'}) {
        if(record.first[f_index]==x or record.first[f_index]=='?') {
            if(x=='.' and cur == 0) sol += solve2(record, f_index+1, s_index, 0);
            else if(x=='.' and cur>0 and s_index<record.second.size() and record.second[s_index]==cur) sol += solve2(record, f_index+1, s_index+1, 0);
            else if(x=='#') sol += solve2(record, f_index+1, s_index, cur+1);
        }
    }
    dp[temp] = sol;
    return sol;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<string, vector<ll>>> records;
    string s;
    while(getline(fin, s)) {
        pair<string, vector<ll>> cur;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                cur.first = s.substr(0, i);
                // num starts at i+1
                stringstream ss(s.substr(i+1, s.size()-i-1));
                while(getline(ss, s, ',')) cur.second.push_back(stoi(s)); 
                break;
            }
        }
        records.push_back(cur);
    }   

    for(auto &x: records) solve1(x, 0, 0);
    fout << sol1 << endl;
    
    ll sol2 = 0;
    for(auto &x: records) {
        int n = x.second.size(), m = x.first.size();
        for(int i=0; i<4; i++) {
            for(int j=0; j<n; j++) {
                x.second.push_back(x.second[j]);
            }
            x.first += ('?'+x.first.substr(0, m));
        }
        sol2 += solve2(x, 0, 0, 0);
        dp.clear();
    }
    fout << sol2 << endl;
}