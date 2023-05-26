#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

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

    int x, n; cin >> x >> n; // street from 0 to x
    // passage = b - a
    set<int> lights {0, x};
    multiset<int> lengths {x};

    for(int i=0; i<n; i++) {
        int cur; cin >> cur;
        // make a cache since we are recalculating some values every time 
        lights.insert(cur);
        if(cur != 0 and cur != x) {
            auto it1 = lights.find(cur), it2 = lights.find(cur);
            it1--; it2++;
            //cout << *(it2) << " " << *(it1) << endl;
            lengths.erase(lengths.find(*(it2) - *(it1)));
            lengths.insert(cur - *(it1));
            lengths.insert(*(it2) - cur);
        }
        cout << *lengths.rbegin() << " ";
    }   
    cout << endl;
}