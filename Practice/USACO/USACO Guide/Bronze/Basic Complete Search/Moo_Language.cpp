#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

void solve() {
    int n, c, p; cin >> n >> c >> p; // words, commas, periods
    // period=. ; comma=,
    map<string, vector<string>> words;
    for(int i=0; i<n; i++) {
        string word, type; cin >> word >> type;
        words[type].push_back(word);
    }
    int sol = 0; // amount of words
    vector<string> sentences;
    /* types:
    type 1: noun + intransitive
    type 2: noun + transitive + nouns (nouns seperated with a comma)

    2 sentences can be joined with a conjunction (max 2)
    after every sentence write a period 
    */
    /* optimal way:
    if intransitive > 0 and ((noun != 2 and transitive > 0) or (transitive == 0)) add type 1  (if periods low then speical case)
    for type 2, its more complicated due to periods and other stuff

    use 1 conjunction -> one less period used and one more word
    */
    

    cout << sol << endl;
}

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}