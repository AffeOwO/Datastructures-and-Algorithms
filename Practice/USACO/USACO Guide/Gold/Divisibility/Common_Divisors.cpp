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
    vector<int> cnt(1e6+1);
    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        cnt[cur]++;
    }
    for(int i=1e6; i>0; i--) {
        int temp = 0;
        for(int j=i; j<=1e6; j+=i) temp += cnt[j];
        if(temp>=2) {
            cout << i << endl;
            break;
        }
    }
}