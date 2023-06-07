#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

bitset<3> r90;
<<<<<<< HEAD
vector<pair<int, int>> rectangles;
=======
vector<pair<pair<int, int>, char>> rectangles;
>>>>>>> 9688c41 (yay)
int side;

bool solve() {
    // if r90[i] == 1, then rectangles[i] {x, y} = {y, x}
<<<<<<< HEAD
    vector<pair<int, int>> cur = rectangles;
    for(int i=0; i<3; i++) {
        if(r90.test(i)) cur[i] = {cur[i].second, cur[i].first};
    }
    // place rectangle always in the upper most left free place and test if possible
    // .first = width, .second = height
    // damn idk how to implement
    // if possible, prine solution here
    
=======
    vector<pair<pair<int, int>, char>> cur = rectangles;
    for(int i=0; i<3; i++) {
        if(r90.test(i)) cur[i].first = {cur[i].first.second, cur[i].first.first};
    }
    // place rectangle always in the upper most left free place and test if possible
    // .first = width, .second = height
    // if possible, print solution here
    if(cur[0].first.first == side) {
        if(cur[1].first.first + cur[2].first.first == cur[0].first.first and cur[1].first.second == cur[2].first.second and cur[1].first.second + cur[0].first.second == side) {
            cout << side << endl;
            for(int i=0; i<cur[0].first.second; i++) {
                for(int j=0; j<cur[0].first.first; j++) cout << cur[0].second;
                cout << endl;
            }
            // print other two rectangles
            for(int i=0; i<cur[1].first.second; i++) {
                for(int j=0; j<cur[1].first.first; j++) cout << cur[1].second;
                for(int j=0; j<cur[2].first.first; j++) cout << cur[2].second;
                cout << endl;
            }
            return true;
        }
        else if(cur[1].first.first == side and cur[2].first.first == side) {
            cout << side << endl;
            for(int i=0; i<cur[0].first.second; i++) {
                for(int j=0; j<cur[0].first.first; j++) cout << cur[0].second;
                cout << endl;
            }
            for(int i=0; i<cur[1].first.second; i++) {
                for(int j=0; j<cur[1].first.first; j++) cout << cur[1].second;
                cout << endl;
            }
            for(int i=0; i<cur[2].first.second; i++) {
                for(int j=0; j<cur[2].first.first; j++) cout << cur[2].second;
                cout << endl;
            }
            return true;
        }
    }
    return false;
>>>>>>> 9688c41 (yay)

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
<<<<<<< HEAD
    rectangles = {l1, l2, l3};
    if(pow(sqrt(area), 2) != area) cout << -1 << endl;
=======
    rectangles = {{l1, 'A'}, {l2, 'B'}, {l3, 'C'}};
    sort(all(rectangles));
    if(pow((int)sqrt(area), 2) != area) cout << -1 << endl;
>>>>>>> 9688c41 (yay)
    else {
        side = sqrt(area);
        do {
            for(int i=0; i<8; i++) {
<<<<<<< HEAD
                r90 = i; // 0 = normal, 1 = x, y = y, x;
                if(solve()) return 0;
            }
        } while(next_permutation(all(rectangles)));
    }
    cout << -1 << endl;
=======
                r90 = i;
                if(solve()) return 0;
            }
        } while(next_permutation(all(rectangles)));
        cout << -1 << endl;
    }
>>>>>>> 9688c41 (yay)
}