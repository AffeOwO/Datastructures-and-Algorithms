#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; fin >> n;
    // deck of size 2n (1, 2, 3, ..., 2n)
    // n cards for bessie and n cards for elsie
    // n rounds, in each round bessie and elsie each play 1 card; highest card gets a point
    vector<bool> cards(2*n); // if cards[i], then elsie owns this card, else bessie
    for(int i=0; i<n; i++) {
        int cur; fin >> cur;
        cur--;
        cards[cur] = true;
    }
        int sol = 0, cnt = 0; // cnt = elsie cards played 
        for(int i=0; i<2*n; i++) {
            if(cards[i]) cnt++;
            else {
                if(cnt == 0) continue;
                else {
                    cnt--;
                    sol++;
                }
            }
        }


    fout << sol << endl;
}