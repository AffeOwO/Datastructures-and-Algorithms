#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

map<char, int> strengths = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}};
bool part = false; // false = part 1; true = part 2

int handtype(string hand) {
    map<char, int> cnt;
    vector<char> chars;
    for(auto &x: hand) {
        if(!cnt.count(x) and (!part or x!='J')) chars.push_back(x);
            cnt[x]++;
        }
    if(part and cnt.count('J')) {
        int jokers = cnt['J'];
        cnt.erase('J');
        pair<char, int> maxi;
        for(auto &x: cnt) {
            if(x.second>maxi.second) maxi = x;
        }
        cnt[maxi.first] += jokers;
    }

    if(cnt.size()==1) return 6;
    else if(cnt.size()==2) {
        if(cnt[chars[0]]==4 or cnt[chars[0]]==1) return 5;
        else if(cnt[chars[0]]==3 or cnt[chars[0]]==2) return 4;
    }
    else if(cnt.size()==3) {
        if(cnt[chars[0]]==3 or cnt[chars[1]]==3 or cnt[chars[2]]==3) return 3;
        else if(cnt[chars[0]]==1 or cnt[chars[1]]==1 or cnt[chars[2]]==1) return 2;
    }
    else if(cnt.size()==4) return 1;
    else return 0;
    return -1; // idk why but this needs to be here for compiling
}

bool cstm(pair<string, ll> p1, pair<string, ll> p2) {
    pair<int, int> types = make_pair(handtype(p1.first), handtype(p2.first)); // 0 = high; 1 = pair; 2 = 2 pairs; 3 = triple; 4 = full house; 5 = 4 of a kind; 6 = 5 of a kind

    if(types.first == types.second) {
        for(int i=0; i<5; i++) {
            int val1, val2;
            if(isdigit(p1.first[i])) val1 = p1.first[i]-'0';
            else val1 = strengths[p1.first[i]];
            if(isdigit(p2.first[i])) val2 = p2.first[i]-'0';
            else val2 = strengths[p2.first[i]];
            if(val1!=val2) return val1<val2;
        }
    }
    return types.first<types.second;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // part 1
    vector<pair<string, ll>> hands(1000);
    for(int i=0; i<1000; i++) {
        string s; getline(fin, s);
        hands[i].first = s.substr(0, 5);
        hands[i].second = stoll(s.substr(6, s.size()-5));
    }
    sort(all(hands), cstm);

    ll sol1 = 0;
    for(ll i=0; i<1000; i++) sol1 += hands[i].second*(i+1);
    fout << sol1 << endl;

    // part 2
    strengths['J'] = 0; // joker strength 
    part = true;
    sort(all(hands), cstm);

    ll sol2 = 0;
    for(ll i=0; i<1000; i++) sol2 += hands[i].second*(i+1);
    fout << sol2 << endl;
}