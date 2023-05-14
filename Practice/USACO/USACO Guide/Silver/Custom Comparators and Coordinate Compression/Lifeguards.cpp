#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

struct Cow {
    int l, r;
};

bool operator<(const Cow a, const Cow b) {
    return a.l < b.l;
}

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    vector<Cow> cows(n);
    for(auto &x: cows) fin >> x.l >> x.r;

    sort(all(cows));
    int total = 0;
    int left = 0, right = 0;
    for(int i=0; i<n; i++) {
        if(cows[i].r>right) {
            left = max(right, cows[i].l);
            total += cows[i].r - left;
            right = cows[i].r;
        }
    }  

    Cow last;
    last.l = cows[n-1].r;
    cows.push_back(last);
    int min_alone = total;
    right = 0;
    for(int i=0; i<n; i++) {
        int cur = min(cows[i+1].l, cows[i].r) - max(cows[i].l, right);
        min_alone = min(min_alone, cur);
        right = max(right, cows[i].r);
    }
    fout << total - max(min_alone, 0) << endl;
}