#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2, m1, m2; cin >> n1 >> n2 >> m1 >> m2;
    vector<int> ind1(n1), ind2(n2);
    vector<vector<int>> edg1(n1), edg2(n2), bae1(n1), bae2(n2);
    for(int i=0; i<m1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ind1[b]++;
        edg1[a].push_back(b);
        bae1[b].push_back(a);
    }   
    for(int i=0; i<m2; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ind2[b]++;
        edg2[a].push_back(b);
        bae2[b].push_back(a);
    }
    
    vector<set<int>> dp1(n1), dp2(n2);
    dp1[0] = {0}; dp2[0] = {0};
    queue<int> q;
    for(int i=0; i<n1; i++) {
        if(ind1[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x: bae1[cur]) {
            for(auto &y: dp1[x]) dp1[cur].insert(y+1);
        }
        for(auto &x: edg1[cur]) {
            ind1[x]--;
            if(ind1[x]==0) q.push(x);
        }
    }
    for(int i=0; i<n2; i++) {
        if(ind2[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x: bae2[cur]) {
            for(auto &y: dp2[x]) dp2[cur].insert(y+1);
        }
        for(auto &x: edg2[cur]) {
            ind2[x]--;
            if(ind2[x]==0) q.push(x);
        }
    }

    vector<int> a1, a2;
    for(auto &x: dp1[n1-1]) a1.push_back(x);
    for(auto &x: dp2[n2-1]) a2.push_back(x);

    int t; cin >> t;
    while(t--) {
        int v; cin >> v;
        int pnt = a2.size()-1;
        bool pos = false;
        for(int i=0; i<a1.size(); i++) {
            while(pnt>0 and a1[i]+a2[pnt]>v) pnt--;
            if(a1[i]+a2[pnt]==v) {
                pos = true;
                break;
            }
        }
        if(pos) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}