#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

bool works(int arr[], int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] % 2 == 0) {return true;}
    }
    return false;
}

void solve() {
    int n; cin >> n;

    set<int> idk;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        idk.insert(temp);
    }
    int sol = 0;
    while(!idk.empty()) {
        int temp = *idk.rbegin();
        idk.erase(temp);
        if(temp%2==0) {
            sol += 1;
            idk.insert(temp/2);
        }
    }
    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }
}