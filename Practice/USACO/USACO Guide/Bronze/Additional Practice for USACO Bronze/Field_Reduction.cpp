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
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    vector<pair<int, int>> p;
    vector<int> x, y;
    bool bx[40000], by[40000];
    int ans = 40000*40000;
    
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        fin >> a >> b;
        p.push_back({a, b});
        if (!bx[a-1]) bx[a-1] = true; x.push_back(a);
        if (!by[b-1]) by[b-1] = true; y.push_back(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int li = 0; li < 4; ++li)
        for (int ri = 0; ri < 4; ++ri)
            for (int ui = 0; ui < 4; ++ui)
                for (int di = 0; di < 4; ++di) {
                    if (ui + di > 3 || ri + li > 3) continue;
                    int l = x[min(li, (int)x.size()-1)];
                    int r = x[max(0, (int)x.size()-1-ri)];
                    int d = y[min(di, (int)y.size()-1)];
                    int u = y[max(0, (int)y.size()-1-ui)];
                    if (l > r || d > u) continue;
                    int c = 0;
                    for (auto i : p)
                        if (l <= i.first && i.first <= r && d <= i.second && i.second <= u) ++c;
                    if (c >= n - 3) ans = min(ans, (r-l)*(u-d));
                }
    fout << ans;

    /*
    // area is (max(x)-min(x))*(max(y)-min(y))
    pair<vector<int>, vector<int>> extrema;
    vector<pair<int, int>> coords;
    for(int i=0; i<n; i++) {
        int x, y; fin >> x >> y;
        extrema.first.push_back(x); extrema.second.push_back(y);
        coords.push_back(pair<int, int> {x, y});
    }
    sort(all(extrema.first)); sort(all(extrema.second)); sort(all(coords));
    int sol = (extrema.first[n-1]-extrema.first[0]) * (extrema.second[n-1]-extrema.second[0]);

    for(int i=0; i<3; i++) {
        // oh this is wrong since a suboptimal removal could also lead to a more optimal removal thus greedy approach wont work
        // bruteforce isnt needed since removing a cow in the mid wont help at all (if cows around > 3)
        // thus we only have to check every combination whicch may hekp        


        
        int cur = sol;
        int rem = -1;
        for(int j=0; j<coords.size(); j++) {
            int temp, temp2;
            pair<int, int> cur_p = coords[j];
            // get current size
            if(cur_p.first == extrema.first[extrema.first.size()-1]) temp = extrema.first[extrema.first.size()-2];
            else temp = extrema.first[extrema.first.size()-1];
            if(cur_p.first == extrema.first[0]) temp -= extrema.first[1];
            else temp -= extrema.first[0];
            if(cur_p.second == extrema.second[extrema.second.size()-1]) temp2 = extrema.second[extrema.second.size()-2];
            else temp2 = extrema.second[extrema.second.size()-1];
            if(cur_p.second == extrema.second[0]) temp2 -= extrema.second[1];
            else temp2 -= extrema.second[0];

            temp *= temp2;
            //cout << cur_p.first << " " << cur_p.second << "   " << temp << endl;
            if(temp<cur) {
                rem = j;
                cur = temp;
            }
        }
        if(rem == -1) continue;
        pair<int, int> temp = coords[rem];
        coords.erase(coords.begin()+rem);
        for(int j=0; j<extrema.first.size(); j++) {
            if(extrema.first[j] == temp.first) {
                extrema.first.erase(extrema.first.begin()+j);
                break;
            }
        }
        for(int j=0; j<extrema.second.size(); j++) {
            if(extrema.second[j] == temp.second) {
                extrema.second.erase(extrema.second.begin()+j);
                break;
            }
        }
        //for(auto &x: coords) cout << x.first << " " << x.second << "   ";
        //cout << endl;
        sol = cur;
    }
    fout << sol << endl;*/
}