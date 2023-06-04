#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<vector<int>> factors;

void factorize(int x, int index) {
    for(int i=1; i<=sqrt(x); i++) {
        if(x%i==0) {
            factors[index].push_back(i);
            factors[index].push_back(x/i);
            if(i==x/i) factors[index].pop_back();
        }
    }
    sort(all(factors[index]));
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    sort(all(nums));
    factors.resize(n);
    for(int i=0; i<n; i++) factorize(nums[i], i);

    int sol = 1e5 + 1;
    vector<int> subjects(m);
    int idk = m;
    int l = 0, r = 0;
    while(true) {
        if(idk>0 and r>n-1) break;
        if(idk>0) {
            for(auto &x: factors[r]) {
                if(x>m) break;
                if(subjects[x-1]==0) idk--;
                subjects[x-1]++;
            }
            r++;
        }
        else {
            for(auto &x: factors[l]) {
                if(x>m) break;
                subjects[x-1]--;
                if(subjects[x-1]==0) idk++;
            }
            l++;
        }
        //for(auto &x: subjects) cout << x << " ";
        //cout << endl;
        if(idk==0) sol = min(sol, nums[r-1]-nums[l]);
    }
    if(sol>1e5) cout << -1 << endl;
    else cout << sol << endl;
    factors.clear();
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}


/*
vector<set<int>> factors;

void factorize(int index, int x) {
    vector<int> primes;
    for(int i=2; i<=sqrt(x); i++) {
        while(x%i==0) {
            x/=i;
            primes.push_back(i);
        }
    }
    if(x>1) primes.push_back(x);
    int cur = 0;
    factors[index].insert(1);
    for(int i=0; i<pow(2, primes.size()); i++) {
        cur++;
        bitset<20> idk(cur);
        int product = 1;
        for(int j=0; j<primes.size(); j++) {
            if(idk.test(j)) product*=primes[j];
        }
        factors[index].insert(product);
    }
}

int n, m; cin >> n >> m;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    sort(all(nums));
    factors.resize(n);
    for(int i=0; i<n; i++) factorize(i, nums[i]);
    
    int l = 0, r = 0;
    int sol = 1e5+1;
    bool covered = false;
    while(true) {
        
    }

    if(sol>1e5) cout << -1 << endl;
    else cout << sol << endl;
*/