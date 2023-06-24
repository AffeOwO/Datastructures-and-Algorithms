#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, x; cin >> n >> x;
    // knowledge = 0 at start, each of the n books has a difficulty
    // check if his knowledge can become x
    vector<int> s1(n), s2(n), s3(n);
    for(auto &x: s1) cin >> x; // 0 = top, back = bottom
    for(auto &x: s2) cin >> x;
    for(auto &x: s3) cin >> x;

    int temp = 0;
    int pnt1 = 0, pnt2 = 0, pnt3 = 0;
    while(pnt1<n and (s1[pnt1] | x) == x) {
        temp |= s1[pnt1];
        pnt1++;
    }
    while(pnt2<n and (s2[pnt2] | x) == x) {
        temp |= s2[pnt2];
        pnt2++;
    }
    while(pnt3<n and (s3[pnt3] | x) == x) {
        temp |= s3[pnt3];
        pnt3++;
    }
    //cout << temp << endl;
    if(temp == x) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}