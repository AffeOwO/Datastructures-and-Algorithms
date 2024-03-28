#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

class Solution {
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            // at most k projects b4 ipo; maximize capital 
            // w init capital; capital[i] required for project i with profit profits[i]
            int sol = w, n = profits.size(), pnt = 0;
            vector<pair<int, int>> idk(n);
            for(int i=0; i<n; i++) idk[i] = make_pair(profits[i], capital[i]);
            sort(all(idk), [](pair<int, int> p1, pair<int, int> p2) {return p1.second<p2.second;});

            if(n<=k) {
                for(int i=0; i<n; i++) {
                    if(idk[i].second<=sol) sol += idk[i].first;
                    else break;
                }
                return sol;
            }

            priority_queue<int> pq;
            while(pnt<n and idk[pnt].second<=sol) pq.push(idk[pnt++].first); 
            while(k-- and !pq.empty()) {
                sol += pq.top();
                pq.pop();
                while(pnt<n and idk[pnt].second<=sol) pq.push(idk[pnt++].first);
            }

            return sol;
        }
    };