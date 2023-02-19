 #include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int sol;
    sol += (n / 5);
    if(n%5 != 0) {
        sol += 1;
    }

    cout << sol << "\n"; 
}