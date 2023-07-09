#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    // array of length 2n
    /*
    - choose some x
    - find a, b which are in the array
    - remove a and b
    - replace x by max{a, b}

    - if possible to remove all elements, print "YES" else print "NO"
    */

    multiset<int> idk;
    vector<int> vec(2*n);
    for(int i=0; i<2*n; i++) {
        int cur; cin >> cur;
        idk.insert(cur);
        vec[i] = cur;
    }
    sort(all(vec));
    // if there is some value more than 2 times in the set, then "NO"
    /*
    - WLOG a>=b
    a = max{idk}
    b can be ignored

    given that in the first opeartion we choose max{idk} and some unknown b, we can now simulate the whole process since we have max{a, b}
    if process works and only one number is remaining, then "YES" else "NO" 
    */

    for(int i=0; i<2*n-1; i++) {
        // let b = i
        multiset<int> cur = idk;
        int x = *cur.rbegin();
        cur.erase(cur.find(x)); cur.erase(cur.find(vec[i]));
        vector<pair<int, int>> operations = {{x, vec[i]}};
        bool bruh = false;
        while(cur.size()) {
            int temp = x-*cur.rbegin();
            x = *cur.rbegin();
            cur.erase(cur.find(x));
            if(!cur.count(temp)) {
                bruh = true;
                break;
            }
            operations.push_back({x, temp});
            cur.erase(cur.find(temp));
        }
        if(bruh) continue;
        cout << "YES" << endl << operations[0].first + operations[0].second << endl;
        for(auto &x: operations) cout << x.first << " " << x.second << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}