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
    map<int, int> sweepy;
    vector<pair<pair<int, int>, int>> idk(n); // .second = original index (coordinate compression)
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        idk[i].first = pair<int, int>{a, b};
        idk[i].second = i;
        sweepy[a]++;
        sweepy[b+1]--;
    }
    sort(all(idk));
    int k = 0, cur = 0;
    for(auto &x: sweepy) {
        cur += x.second;
        k = max(k, cur);
    }
    cout << k << endl;

    vector<int> sol(n);
    vector<int> rooms(k);
    int addi = 0;
    for(int i=0; i<n; i++) {
        while(rooms[(i+addi)%k] >= idk[i].first.first) addi++; // make this loop more efficient
        sol[idk[i].second] = ((i+addi)%k)+1;
        rooms[(i+addi)%k] = idk[i].first.second;
        addi %= k;
    }
    for(auto &x: sol) cout << x << " ";
    cout << endl;
}