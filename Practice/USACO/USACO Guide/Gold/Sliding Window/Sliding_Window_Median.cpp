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

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;

    multiset<int> s1, s2;
    for(int i=0; i<n; i++) {
        if(i-k>=0) {
            if(*s1.rbegin()>=nums[i-k]) {
                s1.erase(s1.find(nums[i-k]));
            }
            else {
                s2.erase(s2.find(nums[i-k]));
            }
        }
        s1.insert(nums[i]);
        if((k%2==0 and s1.size()>s2.size()) or (k%2==1 and s1.size()>s2.size()+1)) {
            s2.insert(*s1.rbegin());
            //cout << s1.count(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
        while(!s1.empty() and !s2.empty() and *s1.rbegin()>*s2.begin()) {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
        if(i-k>=-1) cout << *s1.rbegin() << " ";
    }
    cout << endl;
}