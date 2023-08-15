#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

struct entry {
    int d, id;
    ll val;
    bool operator<(entry idk) {return d<idk.d;}
};

int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, g; fin >> n >> g;
    // each of the cows produces g litres of milk per day
    map<int, ll> cows;
    vector<entry> entries(n);
    for(auto &x: entries) {
        fin >> x.d >> x.id >> x.val;
        cows[x.id] = g;
    }
    sort(all(entries));

    // for(auto &x: entries) cout << x.d << " " << x.id << " " << x.val << endl;
    int sol = 0;

    map<ll, int> lb = {{g, n+1}}; // leaderboard
    for(auto &x: entries) {
        ll cur = cows[x.id];

        if((lb.rbegin()->second)>1 and (lb.rbegin()->first)==cur) sol++;
        else if(cur != (lb.rbegin()->first) and cur+x.val>= (lb.rbegin()->first)) sol++;
        else if(cur == (lb.rbegin()->first) and cur+x.val<= ((++lb.rbegin())->first)) sol++;
        
        //for(auto &x: lb) cout << x.first << " " << x.second << "---";
        //cout << endl;
        //cout << (lb.rbegin()++)->first << " " << lb.rbegin()->first << " " << (++lb.rbegin())->first << endl;

        cows[x.id] += x.val;
        lb[cur+x.val]++;
        lb[cur]--;
        if(lb[cur] == 0) lb.erase(cur);
    }

    fout << sol << endl;
}