#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> s(n);
    for(auto &x: s) cin >> x;
    // prime factorization
    // there are n(n-1)/2 pairs -> bruteforce too slow
    // calculate the gcd({lcm(a, b) | a, b in s})
    // -> gcd({lcm(a, b) | a, b in s}) >= gcd(s)
    // every prime factor which is in at least n-1 numbers is also in the gcd since the lcm will include it as long as there is no pair of numbers not containing it
    
    /* time complexities:
    maybe precompute prime numbers O(sqrt(max(m))*log(log(sqrt(max(m)))))
    prime factorization of n numbers -> O(n*sqrt(m_i)) where m_i is the ith number
    maybe make the final map more efficient
    check for final map O(n*p) 
    */

    // todo do later
    
}

/*
map<int, pair<int, int>> final; // .first > .second
    for(auto &x: s) {
        for(int i=2; i<=sqrt(200000)+1; i++) {
            int cnt = 0;
            while(x%i==0) {
                cnt++;
                x/=i;
            }
            if(!final.count(i)) final[i] = pair<int, int>{20, cnt};
            else {
                if(cnt<final[i].second) final[i] = pair<int, int>{final[i].second, cnt};
                else if(cnt<final[i].first and cnt>final[i].second) final[i].first = cnt;
                else if(cnt==final[i].second) final[i].first = final[i].second;
            }
        }
    }
    ll sol = 1;
    for(auto &x: final) {
        for(int i=0; i<x.second.first; i++) sol *= x.first;
    }
    cout << sol << endl;
*/