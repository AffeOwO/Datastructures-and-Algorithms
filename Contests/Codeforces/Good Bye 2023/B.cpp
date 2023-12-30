#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<ll> primes;
void is_prime(int num) {
    for(ll j=2; j<sqrt(num); j++) {
        if(num%j==0) return;
    }
    for(int i=1; i<100; i++) {
        if(powl(num,i)>1e3) break;
        primes.push_back(pow(num, i));
    }
}

void solve() {
    ll a , b; cin >> a >> b;
    // x>b>a
    if(a==1) cout << b*b << endl;
    else {
        if(gcd(a,b)==1) cout << a*b << endl;
        else {
            for(auto &x: primes) {
                ll temp = b*x;
                if(temp%a==0 and (b%(temp/a)==0 or temp/a==x*x)) {
                    cout << temp << endl;
                    break;
                }
            }   
        }
    }
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2; i<=1e3+1; i++) is_prime(i);
    sort(all(primes));
    int t; cin >> t;
    while(t--) solve();   
}