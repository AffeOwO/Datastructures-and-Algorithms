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
    
    vector<pair<ll, ll>> races(4);
    string s; getline(fin, s);
    stringstream ss(s);
    ll temp = 0;
    while(getline(ss, s, ' ')) {
        if(isdigit(s[0])) {
            races[temp].first = stoll(s);
            temp++;
        }
    }
    getline(fin, s);
    ss.str(s); ss.clear(); ss.seekg(0);
    temp = 0;
    while(getline(ss, s, ' ')) {
        if(isdigit(s[0])) {
            races[temp].second = stoll(s);
            temp++;
        }
    }
    ll sol = 1;
    for(auto &x: races) {
        ll cur = 0;
        for(int i=0; i<=x.first; i++) {
            if(i*(x.first-i)>x.second) cur++;
        }
        if(cur>0) sol *= cur;
    }
    fout << sol << endl;

    // part 2
    pair<ll, ll> p2;
    p2.first = races[0].first*pow(10, 6) + races[1].first*pow(10, 4) + races[2].first*pow(10, 2) + races[3].first;
    p2.second = races[3].second + races[2].second*powl(10, 4) + races[1].second*powl(10, 8) + races[0].second*powl(10, 12);
    
    ll sol2 = 0;
    for(ll i = 0; i<=p2.first; i++) {
        if(i*(p2.first-i)>p2.second) sol2++;
    }

    fout << sol2 << endl;
}