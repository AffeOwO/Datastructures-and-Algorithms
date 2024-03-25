#include <bits/stdc++.h>

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
    ll n, k; cin >> n >> k;
    vector<ll> nums(n);
    for(auto &x: nums) cin >> x;
    sort(all(nums));



    if(nums[0]==nums.back()) cout << 0 << endl;
    else {

        ll pnt1 = 0, pnt2 = n-1, cnt = 0, sol = 0; // pnt1 + 1; n - pnt2
        for(int i=0; i<n; i++) {
            if(nums[i]==nums[pnt1]) pnt1 = i;
            else break;
        }
        for(int i=n-1; i>=0; i--) {
            if(nums[i]==nums[pnt2]) pnt2 = i;
            else break;
        }

        while(true) {
            if(pnt1+1<=n-pnt2) {
                ll temp = nums[pnt1+1]-nums[pnt1];
                if((pnt1+1)*temp<=(k-cnt)) {
                    sol += temp;
                    cnt += (pnt1+1)*temp;
                    pnt1++;
                    for(int i=pnt1; i<n; i++) {
                        if(nums[i]==nums[pnt1]) pnt1=i;
                        else break;
                    }
                }
                else {
                    sol += (k-cnt)/(pnt1+1);
                    break;
                }
            }
            else {
                ll temp = nums[pnt2]-nums[pnt2-1];
                if((n-pnt2)*temp<=(k-cnt)) {
                    sol += temp;
                    cnt += (n-pnt2)*temp;
                    pnt2--;
                    for(int i=pnt2; i>=0; i--) {
                        if(nums[i]==nums[pnt2]) pnt2=i;
                        else break;
                    }
                }
                else {
                    sol += (k-cnt)/(n-pnt2);
                    break;
                }
            }
            if(pnt1>=pnt2 or cnt>=k) break;
        }

        cout << nums.back()-nums[0]-sol << endl;
    }
    // no bin search?
}

/*
int l=0, r=nums.back()-nums[0];
    while(l<r) {
        int mid = (l+r)/2;

    }
*/