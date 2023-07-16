#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

vector<int> primes(2e5+1);
void compute() {
    primes[1] = 1;
    for(int i=2; i<=2e5; i++) {
        if(!primes[i]) {
            for(int j=i; j<=2e5; j+=i) primes[j] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    compute();
    // for(int i=1; i<=100; i++) cout << primes[i] << " ";

    int n; cin >> n;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;

    // find gcd{lcm{nums[i], nums[j]} | 1 <= i < j <= n}
    /*
    lcm{a; b; c} = lcm{a; lcm{b; c}}
    every prime factor which appears in at least n-1 numbers will be in the gcd
    */
   	ll sol = 1;

    map<int, pair<int, int>> factors;
    map<int, int> cnt;
    for(int i=0; i<n; i++) {
        pair<int, int> cur = {primes[nums[i]], 0}; //.first = num; .second = cnt
        while(nums[i]>1) {
            int temp = primes[nums[i]];
            if(temp != cur.first or nums[i] == temp) {
                //if(cur.first == 2) cout << i << " " << cur.second << endl;
                cnt[cur.first]++;
                //if(cur.first == 2) cout << i << " " << cur.second << endl;
                if(nums[i] == temp and temp != cur.first) {
                    // cnt = 1
                    cnt[temp]++;
                    if(!factors.count(temp)) factors[temp] = {690, 690};
                    //cout << factors[temp].first << " " << factors[temp].second << " " << temp << endl;
                    if(factors[temp].first == 1) factors[temp].second = 1;
                    factors[temp] = {1, factors[temp].first};
                    //cout << factors[temp].first << " " << factors[temp].second << " " << temp << endl;
                }
                else if(nums[i] == temp) cur.second++;
                //if(i==0) cout << nums[i] << " " << temp << " " << cur.first << " " << cur.second << endl;
                if(!factors.count(cur.first)) {
                    factors[cur.first] = {690, 690};
                }
                if(cur.second<factors[cur.first].second) factors[cur.first].second = cur.second;
                if(factors[cur.first].second<factors[cur.first].first) factors[cur.first] = {factors[cur.first].second, factors[cur.first].first};
                cur = {temp, 0};
            }
            cur.second++;
            nums[i] /= temp;
        }
    }
    //cout << cnt[2] << endl;
    for(auto &x: factors) {
        //if(x.first == 2) cout << x.second.second << " " << x.second.first << endl;
        if(cnt[x.first]<n-1) continue;
        if(x.second.second == 690 or cnt[x.first] == n-1) sol *= pow(x.first, x.second.first);
        else sol *= pow(x.first, x.second.second);
    }

    cout << sol << endl;
}