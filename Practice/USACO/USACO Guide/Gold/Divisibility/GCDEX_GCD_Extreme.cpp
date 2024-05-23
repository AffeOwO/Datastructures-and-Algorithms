#include <bits/stdc++.h>

//ifstream fin("");
//ofstream fout("");

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll tmp = 1e6;
vector<ll> phi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    phi.resize(tmp+1);
    for(int i=1; i<=tmp; i++) phi[i] = i;
    for(int i=2; i<=tmp; i++) {
        if(phi[i] == i) {
            for(int j=i; j<=tmp; j+=i) phi[j] -= phi[j]/i; 
        }
    }

    vector<ll> sol(tmp+1);
    for(ll i=1; i<=tmp; i++) {
        sol[i] += sol[i-1];
        for(ll j=2*i; j<=tmp; j+=i) sol[j] += phi[j/i]*i;
    }
    

    while(true) {
        cin >> n;
        if(n==0) break;
        
        cout << sol[n] << endl;
    }   
}