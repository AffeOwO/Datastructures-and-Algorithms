#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<int> primes(5e5 + 1); // primes[x] = 1 if x = prime or primes[x] = some prime divisor of x
void compute() {
    primes[1] = 1;
    for(int i=2; i<=5e5; i++) {
        if(!primes[i]) {
            primes[i] = 1;
            for(int j=2*i; j<=5e5; j+=i) primes[j] = i;
        }
    }
}

// all 3 hints used
void solve() {
    int n; cin >> n;
    string s; cin >> s;

    // find the maximum amount of splits for s such that the ratio of D:K in each split is the same
    // a:b = c:d if a*d = b*c
    // compute max splits for every prefix
    // if |K| == 0 or |D| == 0, then sol = |prefix| 
    // divisors of |prefix| dp like approach?
    // prefix = [0, i]
    map<double, int> prev;
    pair<int, int> cnt = {0, 0}; // .first = 'D'; .second = 'K'
    for(int i=0; i<n; i++) {
        if(s[i] == 'D') cnt.first++;
        else cnt.second++;

        if(cnt.first == 0 or cnt.second == 0) cout << i+1 << " ";
        else {
            // how is this just a 1500
            /*
            linear 'function' with c = 0
            y = ax
            multiple possible y values for each x value
            sol = cnt(points on line)
            where line has slope y/x (case with x = 0 handled in if statement above)
            */
            double temp = (double)cnt.second / (double)cnt.first;
            prev[temp]++;
            cout << prev[temp] << " ";
        }
        // if x|y, then for y only the ones work which also work for x
    }
    cout << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    compute();
    // for(int i=0; i<=100; i++) cout << i << " " << primes[i] << endl;
    int t; cin >> t;
    while(t--) solve();
}

/*
vector<pair<int, int>> pref(n+1); // .first = 'D'; .second = 'K'; 1-indexed
    for(int i=1; i<=n; i++) {
        pref[i] = pref[i-1];
        if(s[i-1] == 'D') pref[i].first++;
        else pref[i].second++;
    }
*/