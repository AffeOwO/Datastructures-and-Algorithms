#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n; // start = 1 candy, goal = n candies
    /*
    operation 40 times:
    1) cur = 2cur - 1
    2) cur = 2cur + 1
    */
    if(n%2 == 0) {
        cout << -1 << endl;
        return;
    }
    // first operation = 2 (if possible)
    // every odd integer <= 2^41 - 1 can be reached
    // what is the pattern?
    // if smaller half of difference, then left side (op 1) else right side (op 2)
    vector<int> spells = {2};
    int temp = log2(n);
    pair<int, int> interval = {pow(2, temp) + 1, pow(2, temp+1) - 1}; // to check on which side of tree
    // given n, we can simulate the process with interval checking difference
    while(interval.first < interval.second) {
        int div = (interval.second - interval.first)/2; 
        if(n<interval.first+div) {
            spells.push_back(1);
            interval.second = interval.first+div-1;
        }
        else {
            spells.push_back(2);
            interval.first = interval.first+div+1;
        }
    }
    

    cout << spells.size() << endl;
    for(auto &x: spells) cout << x << " ";
    cout << endl;  // overflow?
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
while(n > 1) {
        int temp = log2(n);
        pair<int, int> interval = {pow(2, temp)+1, pow(2, temp+1) - 1};
        int dif = (interval.second - interval.first)/2; // wrong
        cout << n << " " << interval.first << " " << interval.second << " " << dif << endl;
        if(interval.first+dif>n) {
            // left side of tree (op 1)
            spells.push_back(1);
            n /= 2;
        }
        else {
            spells.push_back(2);
            n /= 2;
        }
    }
*/