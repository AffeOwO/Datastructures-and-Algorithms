#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("convention.in");
    ofstream fout("convention.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, c; fin >> n >> m >> c;
    vector<int> cows(n);
    for(auto &x: cows) fin >> x;
    sort(all(cows));

    // minmax waiting time
    // n cows; m busses where each bus has space c
    // bin search minmax
    int left = 1, right = cows.back(), sol = 1;
    while(left<=right) {
        int mid = (left+right)/2;
        //cout << left << " " << right << " " << mid << endl;
        int bleft = m-1, cnt = 0, fcow = cows[0];
        for(int i=0; i<n; i++) {
            if(cows[i]-fcow>mid or cnt == c) {
                bleft--;
                cnt = 1;
                fcow = cows[i];
            }
            else cnt++;
        }
        if(bleft>=0) {
            sol = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    fout << sol << endl;
}