#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

void find(ll n) {
    ll len_of_num = 1;
    ll num = 1;
    while(true) {
        ll temp;
        temp = (9*len_of_num*pow(10, len_of_num-1));
        if(temp < n) {
            n -= temp;
            num = pow(10, len_of_num);
            len_of_num += 1;
        }
        else {break;}
    }
    n -= 1;
    num += (n/len_of_num);
    string num_str = to_string(num);
    cout << num_str[n%len_of_num] << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    while(n--) {
        ll query;
        cin >> query;        
        find(query);
    }
}