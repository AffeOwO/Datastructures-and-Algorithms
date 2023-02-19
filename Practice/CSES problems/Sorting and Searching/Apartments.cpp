#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define endl "\n"
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    int desired[n], available[m];
    for(int i=0; i<n; i++) {
        cin >> desired[i];
    }
    for(int i=0; i<m; i++) {
        cin >> available[i];
    }
    sort(desired, desired+n);
    sort(available, available+m);
    int p=0;
    int sol = 0;
    for(int i=0; i<n; i++) {
        for(int j=p; j<m; j++) {
            if(abs(desired[i]-available[j]) <= k) {
                sol += 1;
                p+=1;
                break;
            }
            if(available[j]>=desired[i]) {
                break;
            }
            p+=1;
        }
    }
    cout << sol << "\n";
}