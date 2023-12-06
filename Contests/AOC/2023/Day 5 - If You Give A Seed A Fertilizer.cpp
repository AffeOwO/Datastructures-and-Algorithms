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
    
    ll sol = 1e16;
    vector<ll> seeds;
    string s, cur; getline(fin, s);
    stringstream ss(s);
    while(getline(ss, cur, ' ')) {
        if(isdigit(cur[0])) seeds.push_back(stoll(cur));
    }

    vector<ll> cur_val = seeds;
    bool idk = true;
    vector<vector<vector<ll>>> bruh;
    while(getline(fin, s)) {
        if(!isdigit(s[0])) {
            idk = not idk;
            if(idk) bruh.push_back({});
        }
        else {
            bruh.back().push_back({});
            ll start = 0, n = s.size();
            for(ll i=0; i<n; i++) {
                if(!isdigit(s[i]) or i == n-1) {
                    bruh.back().back().push_back(stoll(s.substr(start, i-start+(i==n-1))));
                    start = i+1;
                }
            }
        }
    }
    
    for(auto &x: cur_val) {
        for(auto &y: bruh) {
            ll new_val = -1;
            for(auto &z: y) {
                if(x>=z[1] and x<z[1]+z[2]) {
                    new_val = z[0] + x-z[1];
                    break;
                }
            }
            if(new_val != -1) x = new_val;
        }
        sol = min(x, sol);
    }

    fout << sol << endl;

    // part 2
    vector<pair<ll, ll>> intervals;
    for(ll i=0; i<seeds.size(); i+=2) intervals.push_back({seeds[i], seeds[i]+seeds[i+1]-1});
    // sort(all(intervals));
    
    ll num = -1;
    while(true) {
        num++;
        ll temp = num;
        for(int i=bruh.size()-1; i>=0; i--) {
            for(auto &x: bruh[i]) {
                if(x[0]<=temp and x[0]+x[2]>temp) {
                    temp = x[1] + temp-x[0];
                    break;
                }
            }
        }
        bool sol_found = false;
        for(auto &x: intervals) {
            if(x.first<=temp and x.second>=temp) {
                fout << num << endl;
                sol_found = true;
                break;
            }
        }
        if(sol_found) break;
                        
    }
}