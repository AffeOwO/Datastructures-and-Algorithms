#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t; fin >> n >> t;
    vector<int> cows(n);
    for(auto &x: cows) fin >> x;

    // binary search amount of cows at the same time on stage
    int left = 1, right = n, sol = 1;
    while(left<=right) {
        int mid = (left+right)/2;
        // ...
        multiset<int> idk;
        for(int i=0; i<mid; i++) idk.insert(0);
        for(int i=0; i<n; i++) {
            int temp = *idk.begin();
            idk.erase(idk.begin());
            idk.insert(temp+cows[i]);
        }

        int time = *idk.rbegin();

        if(time<=t) {
            sol = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    fout << sol << endl;
}