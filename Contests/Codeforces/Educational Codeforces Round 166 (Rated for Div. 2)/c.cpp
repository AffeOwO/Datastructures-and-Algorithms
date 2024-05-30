#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> ca(n+m+1), pref1, pref2;
    for(auto &x: ca) cin >> x.first;
    for(auto &x: ca) cin >> x.second;
    vector<ll> sol(n+m+1);
    pref1.push_back(make_pair(0, 0)); pref2.push_back(make_pair(0, 0));
    for(auto &x: ca) {
        if(x.first>x.second) {
            pref1.push_back(x);
            pref1.back().first += pref1[pref1.size()-2].first;
            pref1.back().second += pref1[pref1.size()-2].second;
        }
        else {
            pref2.push_back(x);
            pref2.back().first += pref2[pref2.size()-2].first;
            pref2.back().second += pref2[pref2.size()-2].second;
        }
    }
    //for(auto &x: pref2) cout << x.first << " " << x.second << endl;
    pair<int, int> cur;
    for(int i=0; i<n+m+1; i++) {
        int t = 0; // 0 = coder; 1 = tester
        if(ca[i].first>ca[i].second) cur.first++;
        else {
            cur.second++;
            t = 1;
        }
        if(t==0) {
            if(pref1.size()-1>n) {
                sol[i] = pref2.back().second;
                if(cur.first>n) {
                    sol[i] += pref1[n].first;
                    sol[i] += (pref1.back().second-pref1[n].second-ca[i].second);
                }
                else {
                    sol[i] += pref1[n+1].first;
                    sol[i] -= ca[i].first;
                    sol[i] += (pref1.back().second-pref1[n+1].second);
                }
            }
            else {
                sol[i] = pref1.back().first;
                sol[i] -= ca[i].first;
                sol[i] += pref2[m].second;
                sol[i] += (pref2.back().first-pref2[m].first);
            }
        }
        else {
            if(pref2.size()-1>m) {
                sol[i] = pref1.back().first;
                if(cur.second>m) {
                    sol[i] += pref2[m].second;
                    sol[i] += (pref2.back().first-pref2[m].first-ca[i].first);
                }
                else {
                    sol[i] += pref2[m+1].second;
                    sol[i] -= ca[i].second;
                    sol[i] += (pref2.back().first-pref2[m+1].first);
                }
            }
            else {
                sol[i] = pref2.back().second;
                sol[i] -= ca[i].second;
                sol[i] += pref1[n].first;
                sol[i] += (pref1.back().second-pref1[n].second);
            }
        }
    }
    

    for(auto &x: sol) cout << x << " ";
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}