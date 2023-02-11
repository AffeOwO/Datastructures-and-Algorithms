#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int maxi = 0;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
        if(temp>maxi) {maxi=temp;}
    }
    int sol;
    cout << maxi << endl;


    return sol;
}

int main() {
    cout << "test" << endl;
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        cout << solve() << endl;
    }
}