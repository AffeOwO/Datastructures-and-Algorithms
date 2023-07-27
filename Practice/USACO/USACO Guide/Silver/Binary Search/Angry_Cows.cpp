#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; fin >> n >> k;
    // n haybales and k cows to shoot
    // binsearch min power r
    vector<int> hay(n);
    for(auto &x: hay) fin >> x;
    sort(all(hay));

    if(n<=k) fout << 0 << endl;
    else {
        int left = 1, right = hay.back(), sol = 1;
        while(left<=right) {
            int mid = (left+right)/2;
            int needed = 0, idk = -1;
            for(int i=0; i<n; i++) {
                if(hay[i]>idk) {
                    needed++;
                    idk = hay[i]+2*mid;
                }    
            }

            if(needed<=k) {
                sol = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        fout << sol << endl;
    } 
}