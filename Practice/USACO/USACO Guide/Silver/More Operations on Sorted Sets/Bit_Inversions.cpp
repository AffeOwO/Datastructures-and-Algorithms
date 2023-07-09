#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string idk; cin >> idk; // bit-string of length n
    int n = idk.size(), m; cin >> m;
    vector<char> bitstring(all(idk));
    if(n==1) {
        for(int i=0; i<m; i++) {
            int t; cin >> t;
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }
    else if(n==2) {
        for(int i=0; i<m; i++) {
            int t; cin >> t;
            t--;
            if(bitstring[t] == '0') bitstring[t] = '1';
            else bitstring[t] = '0';
            if(bitstring[0]==bitstring[1]) cout << 2 << " ";
            else cout << 1 << " ";
        }
        cout << endl;        
        return 0;
    }

    set<int> parts = {0, n}; // first and last+1
    multiset<int> vals;
    for(int i=1; i<n; i++) {
        if(idk[i] != idk[i-1]) {
            vals.insert(i-(*(++parts.rbegin())));
            /*
            cout << i << " " << *(++parts.rbegin()) << "---";
            for(auto &x: vals) cout << x << " ";
            cout << "---";
            for(auto &x: parts) cout << x << " ";
            cout << endl;
            */
            parts.insert(i);
        }
    }
    vals.insert(n-*++parts.rbegin());

    for(int i=0; i<m; i++) {
        int q; cin >> q; // query: invert qth bit (1-indexed)
        // output length of longest substring where every bit is the same (only 1s or only 0s)
        // sol = max(parts[i]-parts[i-1])
        q--; // make it 0-indexed

        if(q==0) {
            if(bitstring[1] == bitstring[0]) {
                int temp = *parts.upper_bound(0);
                vals.insert(1); vals.insert(-1 + temp);
                vals.erase(vals.find(temp));
                parts.insert(1);
            }
            else {
                int temp = *parts.upper_bound(1);
                vals.insert(temp);  
                vals.erase(vals.find(1)); vals.erase(vals.find(temp-1));
                parts.erase(1);
            }
        }
        else if(q==n-1) {
            if(bitstring[n-1] == bitstring[n-2]) {
                int temp = n - *--parts.find(n);
                vals.insert(1); vals.insert(-1 + temp);
                vals.erase(vals.find(temp));
                parts.insert(n-1);
            }
            else {
                int temp = n - *--parts.find(n-1);
                vals.insert(temp);
                vals.erase(vals.begin()); vals.erase(vals.find(temp-1));
                parts.erase(n-1);
            }
        }
        else {
            if(bitstring[q-1] == bitstring[q+1]) {
                if(bitstring[q] == bitstring[q-1]) {
                    auto temp = parts.upper_bound(q);
                    int t2 = *temp, t1 = *--temp;
                    vals.insert(1); vals.insert(t2-q-1); vals.insert(q-t1);
                    vals.erase(vals.find(t2-t1));
                    parts.insert(q); parts.insert(q+1);
                }
                else {
                    int t1 = *--parts.find(q), t2 = *parts.upper_bound(q+1);
                    vals.insert(t2-t1);
                    vals.erase(vals.begin()); vals.erase(vals.find(t2-q-1)); vals.erase(vals.find(q-t1));
                    parts.erase(q); parts.erase(q+1);
                }
            }
            else {
                if(bitstring[q-1] == bitstring[q]) {
                    int t2 = *parts.upper_bound(q+1), t1 = *--parts.find(q+1);
                    vals.insert(t2-q); vals.insert(q-t1);
                    vals.erase(vals.find(t2-q-1)); vals.erase(vals.find(q-t1+1));
                    parts.erase(q+1);
                    parts.insert(q);
                }
                else {
                    int t2 = *parts.upper_bound(q), t1 = *--parts.find(q);
                    vals.insert(t2-q-1); vals.insert(q-t1+1);
                    vals.erase(vals.find(t2-q)); vals.erase(vals.find(q-t1));
                    parts.erase(q);
                    parts.insert(q+1);
                }
            }
        }

        /*
        for(auto &x: parts) cout << x << " ";
        cout << endl;
        for(auto &x: vals) cout << x << " ";
        cout << endl;
        */

        if(bitstring[q] == '0') bitstring[q] = '1';
        else bitstring[q] = '0';
        cout << *vals.rbegin() << " ";
    }
    cout << endl;
}