#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    // calculate a+b without using arithmetic operators
    int a, b; cin >> a >> b;
    int axorb = ~(a&b)&(a|b);
    int sum = 2*(a&b)+axorb;
    cout << sum << endl;
}