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

bool comp_s(pair<int, int> s1, pair<int, int> s2) {return s1.second > s2.second;} // sort descending order by .second
bool comp_n(int a, int b) {return a > b;} // sort descending order


int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r; fin >> n >> m >> r;
    vector<int> cows(n);
    for(auto &x: cows) fin >> x;
    vector<pair<int, int>> shops(m);
    for(auto &x: shops) fin >> x.first >> x.second; // .first = milk; .second = price
    vector<int> neighbours(r);
    for(auto &x: neighbours) fin >> x;

    sort(all(cows), comp_n);
    sort(all(shops), comp_s);
    sort(all(neighbours), comp_n);
    
    ll sol = 0;
    int cur_cow = 0, cur_shop = 0, cur_neighbour = 0, last_milked;
    vector<int> cache(m);
    vector<ll> milk_sold(n);
    for(auto x: cows) {
        while(true) {
            ll idk = (shops[cur_shop].second * min(shops[cur_shop].first-cache[cur_shop], x));
            sol += idk;
            milk_sold[cur_cow] += idk;
            if(x>=shops[cur_shop].first-cache[cur_shop]) {
                x -= (shops[cur_shop].first-cache[cur_shop]);
                cur_shop++;
                if(cur_shop == m) {
                    last_milked = cur_cow; // last_milked has been milked for cache[m] if loop breaks here
                    cur_cow++;
                    break;
                }
            }
            else {
                last_milked = cur_cow;
                cur_cow++;
                cache[cur_shop] = x;
                break;
            }
        }
        if(cur_shop==m) break;
    }
    while(cur_cow<n and cur_neighbour<r) {
        sol += neighbours[cur_neighbour];
        cur_cow++;
        cur_neighbour++;
    }
    for(int i=last_milked; i>=0; i--) {
        if(cur_neighbour>=r) break;
        if(neighbours[cur_neighbour]>milk_sold[i]) {
            sol -= milk_sold[i];
            sol += neighbours[cur_neighbour];
            cur_neighbour++;
        }
        else break;
    }

    fout << sol << endl;
}

/*
ll pos_milk = 0;
        int temp = 0, ava_milk = x, if_sold = -1;
        while(ava_milk>0 and cur_shop+temp<m) {
            pos_milk += (shops[cur_shop+temp].second * min(shops[cur_shop+temp].first, ava_milk));
            if(ava_milk<shops[cur_shop+temp].first) {
                if_sold = ava_milk;
                break;
            }
            ava_milk -= min(shops[cur_shop+temp].first, ava_milk);
            temp++;
        }
        if(cur_neighbour < r and neighbours[cur_neighbour] > pos_milk) {
            cur_neighbour++;
            
        }
*/