#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);

    // part 1
    string cur;
    int sol = 0;
    vector<string> lines;
    while(getline(fin, cur)) {
        vector<char> nums;
        lines.push_back(cur);
        for(auto &x: cur) {
            if(isdigit(x)) nums.push_back(x);
        }
        sol += (10*(nums[0]-'0') + (nums.back()-'0'));
    }
    fout << sol << endl;

    // part 2
    map<string, char> idk = {{"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};
    int sol2 = 0;
    for(auto &x: lines) {
        vector<char> nums2;
        int n = x.size();
        for(int i=0; i<n; i++) {
            if(isdigit(x[i])) nums2.push_back(x[i]);
            else {
                if(n-i>=3 and idk.count(x.substr(i, 3))) nums2.push_back(idk[x.substr(i, 3)]);
                else if(n-i>=4 and idk.count(x.substr(i, 4))) nums2.push_back(idk[x.substr(i, 4)]);
                else if(n-i>=5 and idk.count(x.substr(i, 5))) nums2.push_back(idk[x.substr(i, 5)]);
            }
        }

        sol2 += (10*(nums2[0]-'0') + (nums2.back()-'0'));
    }

    fout << sol2 << endl;
}