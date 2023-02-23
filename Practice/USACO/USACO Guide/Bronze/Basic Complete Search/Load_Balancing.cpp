#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int n, b;
set<int> hashy_x, hashy_y;
vector<pair<int, int>> nums;

int get_max(int arr[4]) {
    int largest=-1;
    for(int i=0; i<4; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int fields(int boarders[2]) {
    int temp[4] = {0, 0, 0, 0};
    for(auto x: nums) {
        if(x.first < boarders[0]) {
            if(x.second < boarders[1]) {
                temp[0]++;
            }
            else {
                temp[1]++;
            }
        }
        else {
            if(x.second < boarders[1]) {
                temp[2]++;
            }
            else {
                temp[3]++;
            }
        }
    }

    int ret = get_max(temp);
    return ret;
}

int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fin >> n >> b;
    for(int i=0; i<n; i++) {
        int x, y;
        fin >> x >> y;
        pair<int, int> temp = {x, y};
        nums.push_back(temp);
        hashy_x.insert(x);
        hashy_y.insert(y);
    }

    int cur_boarders[2] = {0, 0};  // boarders
    int sol = 100;
    for(auto x: hashy_x) {
        for(auto y: hashy_y) {
            cur_boarders[1] = y;
            int temp = fields(cur_boarders);
            if(temp < sol) {
                sol = temp;
            }
        }
        cur_boarders[0] = x;
    }
    fout << sol << endl;
    //for(auto x: hashy_x) {
    //    cout << x.first << ": ";
    //    for(int j=0; j<size(x.second); j++) {
    //        cout << x.second[j] << " ";
    //    }
    //    cout << endl;
    //}
}