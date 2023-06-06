#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n, k, q; cin >> n >> k >> q;// k=min vac days, q = max deg
    vector<bool> weather((int)n);
    for(int i=0; i<n; i++) {
        ll idk; cin >> idk;
        if(idk>q) weather[i] = false;
        else weather[i] = true;
    }
    // find intervals >k and then yea use my brain
    ll start = 0;
    ll sol = 0;
    for(ll i=0; i<n; i++) {
        if((weather[i] == false and weather[start] == true) ) {
            if(i-start>=k) {
                ll length = i-start-k+1;
                sol += (length*(length+1)/2);
            }
            start = i;
        }
        else if(weather[start] == false and weather[i] == true) start = i;
    }
    // i==n-1 and weather[i] == true
    if(weather[n-1] == true) {
        ll cnt;
        for(ll i=n-1; i>=0; i--) {
            if(!weather[i]) break;
            cnt = i;
        }
        cnt = n-cnt;
        if(cnt>=k) {
            cnt -= k; cnt++;
            sol += (cnt*(cnt+1)/2);
        }
    }
    
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}