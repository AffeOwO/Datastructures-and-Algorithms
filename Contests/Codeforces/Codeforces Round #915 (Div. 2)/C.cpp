#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, ntemp; cin >> n; ntemp = n;
    string s; cin >> s;
    map<char, int> cnt;
    vector<char> temp, ss, sorted_ss;
    for(auto &x: s) {
        if(!cnt.count(x)) temp.push_back(x);
        cnt[x]++;
        ss.push_back(x);
    }
    sorted_ss = ss;
    sort(all(temp)); sort(all(sorted_ss));
    int pnt = temp.size()-1;
    int sol = 0;
    vector<pair<char, int>> subseq;

    for(int i=0; i<n; i++) {
        if(cnt[temp[pnt]]==0 and pnt==0) break;
        if(ss[i] != temp[pnt]) cnt[ss[i]]--;
        else {
            subseq.push_back(make_pair(ss[i], i));
            cnt[ss[i]]--;
            while(pnt>=0 and cnt[temp[pnt]]==0) pnt--;
        }
    }
    
    int k = subseq.size();
    for(int i=0; i<k/2; i++) {
        ss[subseq[i].second] = subseq[k-i-1].first;
        ss[subseq[k-i-1].second] = subseq[i].first;
    }
    for(int i=0; i<k; i++) {
        if(subseq[i].first!=subseq[0].first) {
            sol = k-i;
            break;
        }
    }

    if(sorted_ss!=ss) cout << -1 << endl;
    else cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}