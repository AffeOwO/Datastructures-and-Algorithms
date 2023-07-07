#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ll n; 

void solve() {
    cin >> n;
    
    if(n<7) cout << "NO" << endl;
    else {
        // tf how you gon binary search this :sob:
        ll left = 2, right = 1e9;
        bool sol = false;
        while(left<=right and !sol) {
            ll mid = (left+right)/2, cur = n;
            vector<ll> converted;
            while(cur) {
                converted.push_back(cur%mid);
                cur /= mid;
            }
            
            /*
            cout << left << " " << right << " " << mid << " ";
            for(auto &x: converted) cout << x;
            cout << endl;
            */
            if(converted.size()<3) {
                right = mid-1;
                continue;
            }
            bool temp = true, bruh = false; // works -> break loop
            for(auto &x: converted) {
                if(x!=1) temp = false;
                if(x>1) {
                    right = mid-1;
                    bruh = true;
                }
            }
            if(bruh) continue;
            if(temp) {
                sol = true;
                break;
            }
            else {
                // no digits > 1 but some 0s
                left = mid+1;
            }
        }
        if(sol) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    // binary search the base in which we write the number 
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}

/*
// is there a snowflake, wehre each node has k "children"


    // works for k iff n >= k(k+1) + 1 and when n is represented in base k, its 1111111 (no 0s) -> (n-1) has to be divisible by k
    if(n<7) cout << "NO" << endl;
    else {
        vector<ll> divi;
        for(ll i=2; i<=sqrt(n); i++) {
            if((n-1)%i==0) {
                divi.push_back(i);
                divi.push_back((n-1)/i);
                if(i==sqrt(n)) divi.pop_back();
            }
        }
        sort(all(divi));
        for(auto &x: divi) {
            ll cur = 0, temp = 0;
            if(n<x*(x+1)+1) break;
            while(true) {
                if(cur>=n) break;
                cur += pow(x, temp);
                temp++;
            }
            if(cur==n) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
*/