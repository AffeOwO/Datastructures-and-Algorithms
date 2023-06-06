#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bitset<3> r90;
vector<pair<int, int>> rectangles;
int side;

bool solve() {
    // if r90[i] == 1, then rectangles[i] {x, y} = {y, x}
    vector<pair<int, int>> cur = rectangles;
    for(int i=0; i<3; i++) {
        if(r90.test(i)) cur[i] = {cur[i].second, cur[i].first};
    }
    // place rectangle always in the upper most left free place and test if possible
    // .first = width, .second = height
    // damn idk how to implement
    // if possible, prine solution here
    

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    pair<int, int> l1, l2, l3;
    int x, y; cin >> x >> y;
    l1.first = x; l1.second = y;
    cin >> x >> y;
    l2.first = x; l2.second = y;
    cin >> x >> y;
    l3.first = x; l3.second = y;
    int area = l1.first*l1.second + l2.first*l2.second + l3.first*l3.second;
    rectangles = {l1, l2, l3};
    if(pow(sqrt(area), 2) != area) cout << -1 << endl;
    else {
        side = sqrt(area);
        do {
            for(int i=0; i<8; i++) {
                r90 = i; // 0 = normal, 1 = x, y = y, x;
                if(solve()) return 0;
            }
        } while(next_permutation(all(rectangles)));
    }
    cout << -1 << endl;
}