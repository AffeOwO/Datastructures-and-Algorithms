#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    int ind1, indmax;
    for(int i=0; i<n; i++) {
        int idk; cin >> idk;
        nums[i]=idk;
        if(idk==1) ind1 = i+1;
        if(idk==n) indmax = i+1;
    }
    if(ind1 == 1) {
        cout << 2 << " " << indmax << endl;
    }
    else if(ind1 == n) {
        cout << n-1 << " " << indmax << endl;
    }
    else if(nums[ind1-2]!=2 and nums[ind1]!=2) {
        int temp;
        for(int i=1; i<=n; i++) {
            if(nums[i-1]==2) {
                temp = i+1;
                break;
            }
        }
        if(temp>ind1) cout << indmax << " " << ind1+1 << endl;
        else cout << indmax << " " << ind1-1 << endl;
    }
    else if(indmax != n and indmax != 1) {
        if(nums[ind1]==2) cout << ind1+1 << " ";
        else cout << ind1-1 << " ";
        if(indmax>ind1) cout << indmax+1 << endl;
        else cout << indmax-1 << endl;
    }
    else {
        if(nums[ind1]==2 and indmax>ind1) cout << ind1+1 << " " << indmax << endl;
        else if(nums[ind1-2]==2 and indmax<ind1) cout << ind1-1 << " " << indmax << endl;
        else cout << ind1 << " " << indmax << endl;
    }

    // optimal: nums[0]=1, nums[n-1]=2 -> swap big with small
    // -> make neighbour of nums[x] as big as possilbe such that nums[x]=1
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();   
}

/*
// 2 is a neighbour of 1 and max is on edge
        pair<int, int> sol{1, nums[1]};
        if(nums[n-2]>sol.second) sol = {n, nums[n-2]};
        for(int i=1; i<n-1; i++) {
            int cur = min(nums[i-1], nums[i+1]);
            if(cur>sol.second) sol = {i+1, cur};
        }
        cout << ind1 << " " << sol.first << endl;
        */