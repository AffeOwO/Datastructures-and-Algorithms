#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bool check(ll n) {
    if(n>9876543210 or n<1023456789) return false;
    set<int> idk;
    while(n>0) {
        idk.insert(n%10);
        n/=10;
    }
    return idk.size()==10;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // maximum prime number is sqrt(9876543210 - 8) < 99381, thus we only need to precompute prime numbers < 99381
    vector<int> primes;
    bitset<100000> sieve;
    int maxi = 99381; 
    for(int i=2; i<maxi; i++) {
        if(sieve.test(i)) continue;
        primes.push_back(i);
        for(int j=2*i; j+i<maxi; j+=i) {
            sieve.set(j, 1);
        }
    }

    int sol = 0;
    for(int i=0; i<primes.size(); i++) {
        for(int j=0; j<primes.size(); j++) {
            ll N = pow(primes[i], 2) + pow(primes[j], 3);
            if(check(N)) sol++; 
        }
    }

    cout << sol << endl;
}