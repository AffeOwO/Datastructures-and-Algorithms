#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
const __int128 M = ((ll)1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);

string s1, s2;
ll b = B; 
vector<ll> h;

ll ha(int i) {
    //  s2[i] -> s2
    if(i>s1.size()) return h[i];
    return ((h[i]-(__int128)h[i-s1.size()]*b)%M+M)%M;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s1 >> s2;
    if(s1.size()>s2.size()) {
        cout << 0 << endl;
        return 1;
    }
    h.resize(s2.size());
    h[0] = (s2[0]-'a')+1;
    for(int i=1; i<s2.size(); i++) {
        h[i] = (((__int128)h[i-1]*B)%M+(s2[i]-'a')+1)%M;
        b = ((__int128)b*B)%M;
    }
    cout << b << endl;
    

    set<ll> sol;
    map<char, int> orig, cur;
    for(auto &x: s1) orig[x]++;
    int pnt = -1*s1.size();
    for(int i=0; i<s2.size(); i++) {
        cur[s2[i]]++;
        if(pnt>=0) {
            cur[s2[pnt]]--;
            if(cur[s2[pnt]]==0) cur.erase(s2[pnt]);
        }
        pnt++;

        if(cur==orig) {
            // fix hash function
            cout << i << " " << ha(i) << endl;
            ll tmp = ha(i);
            sol.insert(tmp);
        }
        
    }


    cout << sol.size() << endl;
}