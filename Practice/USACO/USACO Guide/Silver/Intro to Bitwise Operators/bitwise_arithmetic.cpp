#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

// no arithmetic operators
int add(int a, int b) {
    while(b>0) {
        int carry = a&b;
        a^=b;
        b = carry<<1;
    }
    return a;
}

// no arithmetic operators
int multiply(int a, int b) {
    int c = 0;
    while(b>0) {
        if((b&1)) c = add(c, a);
        a<<=1;
        b>>=1;
    }
    return c;
}

// calculate xor using bitwise-and and bitwise-or
int xor_(int a, int b) {
    return ~(a&b)&(a|b);
}

// add numbers using bitwise-and and bitwise-or
int add2(int a, int b) {
    return 2*(a&b)+xor_(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b; cin >> a >> b;
    cout << "a+b=" << add(a, b) << endl;
    cout << "a*b=" << multiply(a, b) << endl;
    cout << "a xor b=" << xor_(a, b) << endl;
    cout << "a+b=" << add2(a, b) << endl;
}