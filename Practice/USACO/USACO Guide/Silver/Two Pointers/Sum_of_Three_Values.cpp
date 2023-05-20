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
    
    int n, x; cin >> n >> x;
    vector<pair<int, int>> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i].first;
        nums[i].second = i+1;
    }
    sort(all(nums));

    for(int i=0; i<n; i++) {
        int target;
        int l = 0, r = n-1;
        while(l!=r) {
            target = x-nums[i].first;
            if(l != i and r != i and nums[l].first + nums[r].first == target) {
                cout << nums[l].second << " " << nums[r].second << " " << nums[i].second << endl;
                return 0;
            }
            else if(nums[l].first + nums[r].first < target) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

/*
for(int i=0; i<n; i++) {
        // now two sum x-nums[i] without nums[i]
        unordered_map<int, int> idk; // 2-sum
        for(int j=i+1; j<n; j++) {
            //if(j==i) continue;
            if(idk.count(nums[j])) {
                cout << idk[nums[j]]+1 << " " << i+1 << " " << j+1 << endl;
                return 0;
            }
            idk[x-nums[i]-nums[j]] = j;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    */