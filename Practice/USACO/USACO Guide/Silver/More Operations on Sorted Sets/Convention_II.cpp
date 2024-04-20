#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

ifstream fin("convention2.in");
ofstream fout("convention2.out");

struct tmp {
    int a, t, s;
    bool operator<(const tmp &y) const {return s>y.s;}
};

bool cmp(tmp t1, tmp t2) {return t1.a<t2.a;}

void solve() {
    int n; fin >> n;
    vector<tmp> vec(n); // {{a, t}, seniority} // seniority 0 is highest, n-1 is lowest
    for(int i=0; i<n; i++) {
        fin >> vec[i].a >> vec[i].t;
        vec[i].s = i;
    }
    sort(all(vec), cmp);
    // for(auto &x: vec) cout << x.a << " " << x.t << " " << x.s << endl;

    priority_queue<tmp> pq;
    
    /*for(auto &x: vec) pq.push(x);
    while(!pq.empty()) {
        cout << pq.top().s << " " << pq.top().a << " " << pq.top().t << endl;;
        pq.pop();
    }*/

    int cur = vec[0].a, maxi = 0, pnt = 0;

    for(int i=0; i<n; i++) {
        pnt = i; // pnt will point to the first "new" element
        if(vec[i].a == vec[0].a) {
            pq.push(vec[i]);
        }
        else break;
    }
    
    // if cow x finishes at time t, then y can start eating at time t+1 
    while(true) {
        maxi = max(maxi, cur-pq.top().a);
        // cout << maxi << " " << cur << " " << pq.top().a << " " << pq.top().t << " " << pq.top().s << endl;
        cur += pq.top().t;
        pq.pop();
        if(pq.empty() and pnt == n) break;

        if(pq.empty()) cur = max(cur, vec[pnt].a);
        for(int i=pnt; i<n; i++) {
            if(vec[i].a>cur) break;
            pq.push(vec[i]);
            pnt++;
        }
    }

    fout << maxi << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}