#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("cruise.in");
    ofstream fout("cruise.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; fin >> n >> m >> k;
    vector<pair<int, int>> ports(n);
    for(auto &x: ports) {
        fin >> x.first >> x.second;
        x.first--; x.second--;
    }
    vector<char> path(m);
    for(auto &x: path) fin >> x;
    
    vector<int> succ(n);
    for(int i=0; i<n; i++) {
        int temp = i;
        for(int j=0; j<m; j++) {
            if(path[j]=='L') temp = ports[temp].first;
            else temp = ports[temp].second;
        }
        succ[i] = temp;
    }
    int cnt = 0, cur = 0;
    while(true) {
        cur = succ[cur];
        cnt++;
        if(cnt==k) {
            fout << cur+1 << endl;
            return -1;
        }
        if(cur==0) break;
    }
    k %= cnt;
    int sol = 0;
    for(int i=0; i<k; i++) sol = succ[sol];
    fout << sol+1 << endl;
}

/*
int cnt = 0, cur = 0;
    while(true) {
        for(int j=0; j<m; j++) {
            if(path[j]=='L') cur = ports[cur].first;
            else cur = ports[cur].second;
        }
        cnt++;
        if(cnt==k) {
            fout << cur+1 << endl;
            return -1;
        }
        if(cur==0) break;
    }
    k %= cnt;
    for(int i=0; i<k; i++) {
        for(int j=0; j<m; j++) {
            if(path[j]=='L') cur = ports[cur].first;
            else cur = ports[cur].second;
        }
    }
    fout << cur+1 << endl;
*/