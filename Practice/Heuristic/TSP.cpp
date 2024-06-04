#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
/* const ll M = (1<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng); */

int n;
vector<pair<ld, ld>> coords;

ld eval(vector<int> route) {
    ld ret = sqrtl(pow(coords[route.back()].first-coords[route[0]].first, 2)+pow(coords[route.back()].second-coords[route[0]].second, 2));
    for(int i=0; i<n-1; i++) {
        ret += sqrtl(pow(coords[route[i+1]].first-coords[route[i]].first, 2) + pow(coords[route[i+1]].second-coords[route[i]].second, 2));
    }
    return ret;
}

ld P(ld cur, ld next, ld t) {
    if(cur>next) return 1;
    return exp((cur-next)/t);
}

int main() {
    ifstream fin("TSP.in");
    ofstream fout("TSP.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    mt19937 gen(random_device{}());
    uniform_real_distribution<> dis(0.0, 1.0);

    fin >> n;
    uniform_int_distribution<> din(0, n-1);
    coords.resize(n);
    for(auto &x: coords) fin >> x.first >> x.second;
    auto now = chrono::steady_clock::now;
    vector<int> route(n), next_route;
    for(int i=0; i<n; i++) route[i] = i; 

    ld sol = eval(route);
    ld cur = sol, next;
    auto start = now();
    auto elapsed = now()-start;
    ld t = 1e8;
    while(elapsed<0.8s) {
        t *= 0.9;

        int f = din(gen), s = din(gen);
        while(f==s) s = din(gen);
        if(f>s) swap(f, s);
        next_route = route;
        for(int i=f; i<(s+f)/2; i++) swap(next_route[i], next_route[s-i+f]);
        next = eval(next_route);

        sol = min(sol, cur);
        if(P(cur, next, t)>=dis(gen)) {
            route = next_route;
            cur = next;
        }
        elapsed = now()-start;
    }

    cout << setprecision(15) << sol << endl; 
}