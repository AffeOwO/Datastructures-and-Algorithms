#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"

void solve(vector<pair<int, int>>& arr, int n, int from, int to, int aux) {
    if(n==1) {
        arr.push_back({from, to});
        return;
    }
    solve(arr, n-1, from, aux, to);
    arr.push_back({from, to});
    solve(arr, n-1, aux, to, from);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<pair<int, int>> x;

    solve(x, n, 1, 3, 2);

    cout << x.size() << endl;
    for(auto i : x) {
        cout << i.first << " " << i.second << endl;
    }
}