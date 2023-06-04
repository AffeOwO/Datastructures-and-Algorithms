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

    int n, t; cin >> n >> t;
    int k; cin >> k; // easy-version -> t=1

    int left = 1, right = n;
    while(left<right) {
        int mid = (left+right)/2;
        cout << "? " << left << " " << mid << endl << flush;
        int x; cin >> x;
        int zeros = (mid-left+1-x); // amount of zeros between left and mid
        if(zeros<k) {
            k-=zeros;
            left = mid+1;
        }
        else {
            right = mid;
        }
    }
    cout << "! " << right << endl << flush;
}