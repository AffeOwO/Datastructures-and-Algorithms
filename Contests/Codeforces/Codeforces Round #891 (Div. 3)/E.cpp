#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    ll n; cin >> n;

    if(n==1) {
        int trash; cin >> trash;
        cout << 1 << endl;
        return;
    }

    vector<pair<ll, int>> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(all(nums));
    vector<ll> sol(n);
    ll temp = 0;
    for(int i=0; i<n; i++) temp += abs(nums[n/2].first-nums[i].first);
    if(n%2==1) {
        sol[nums[n/2].second] = temp;
        for(int i=n/2-1; i>=0; i--) {
            sol[nums[i].second] = sol[nums[i+1].second]+(nums[i+1].first-nums[i].first)*(n-2*(i+1));
        }
        for(int i=n/2+1; i<n; i++) {
            sol[nums[i].second] = sol[nums[i-1].second]+(nums[i].first-nums[i-1].first)*(2*i-n);
        }
    }
    else {
        sol[nums[n/2].second] = temp;
        sol[nums[n/2-1].second] = temp;
        for(int i=n/2-2; i>=0; i--) {
            sol[nums[i].second] = sol[nums[i+1].second]+(nums[i+1].first-nums[i].first)*(n-2*(i+1));
        }
        for(int i=n/2+1; i<n; i++) {
            sol[nums[i].second] = sol[nums[i-1].second]+(nums[i].first-nums[i-1].first)*(2*i-n);
        }
    }


    for(auto &x: sol) cout << x+n << " ";
    cout << endl;
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
for(int i=0; i<n; i++) {
        ll addi = 0; // addi = sum(j=0 -> n)  |nums[i]-nums[j]|
        if(n%2==0) {
            if(idk[i]!=nums[n/2] and idk[i]!=nums[n/2-1]) {
                if(idk[i]<nums[n/2]) {
                    int left = 0, right = n-1, cur = 0;
                    while(left<=right) {
                        int mid = (left+right)/2;
                        if(nums[mid]<=idk[i]) {
                            left = mid+1;
                            cur = mid;
                        }
                        else right = mid-1;
                    }
                    // rightmost
                    addi = (n-2*(cur+1))*(nums[n/2-1]-idk[i]);
                }
                else {
                    int left = 0, right = n-1, cur = n-1;
                    while(left<=right) {
                        int mid = (left+right)/2;
                        if(nums[mid]>=idk[i]) {
                            right = mid-1;
                            cur = mid;
                        }
                        else left = mid+1;
                    }
                    // leftmost
                    addi = (2*(cur)-n)*(idk[i]-nums[n/2]);
                }
            }
        }
        else {
            if(idk[i]!=nums[n/2]) {
                if(idk[i]<nums[n/2]) {
                    int left = 0, right = n-1, cur = 0;
                    while(left<=right) {
                        int mid = (left+right)/2;
                        if(nums[mid]<=idk[i]) {
                            left = mid+1;
                            cur = mid;
                        }
                        else right = mid-1;
                    }
                    // rightmost
                    addi = (n-2*(cur+1))*(nums[n/2]-idk[i]);
                }
                else {
                    int left = 0, right = n-1, cur = n-1;
                    while(left<=right) {
                        int mid = (left+right)/2;
                        if(nums[mid]>=idk[i]) {
                            right = mid-1;
                            cur = mid;
                        }
                        else left = mid+1;
                    }
                    // leftmost
                    addi = (2*(cur)-n)*(idk[i]-nums[n/2]);
                }
            }
        }
        cout << n+addi+temp << " ";
    }
    cout << endl;
*/