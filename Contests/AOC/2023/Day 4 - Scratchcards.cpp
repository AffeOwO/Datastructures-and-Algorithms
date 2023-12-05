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
    int sol = 0;
    string s;
    vector<pair<set<string>, set<string>>> cards;
    while(getline(fin, s)) {
        stringstream ss(s);
        string cur;
        vector<string> nums;
        set<string> nums_win, a, b;
        cards.push_back(make_pair(a, b));
        while(getline(ss, cur, ' ')) {
            if(isdigit(cur[cur.size()-1])) {
                if(nums.size()<10) {
                    nums.push_back(cur);
                    cards.back().first.insert(cur);
                }
                else {
                    nums_win.insert(cur);
                    cards.back().second.insert(cur);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<10; i++) {
            cnt += nums_win.count(nums[i]);
        }
        sol += (1<<cnt)/2;       
    }

    fout << sol << endl;

    // part 2
    int n = cards.size(), sol2 = 0;
    vector<int> addi(n+12, 1);
    for(int i=0; i<n; i++) {
        sol2 += addi[i];
        int temp = 0;
        for(auto &x: cards[i].first) temp += cards[i].second.count(x);
        for(int j=1; j<=temp; j++) addi[i+j] += addi[i];
    }
    fout << sol2 << endl;
}