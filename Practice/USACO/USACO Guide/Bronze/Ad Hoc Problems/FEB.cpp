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
    
    int n; cin >> n;
    vector<char> s(n);
    int f_cnt = 0;
    for(auto &x: s) {
        cin >> x;
        if(x=='S') x = 'F';
        if(x=='F') f_cnt++;
    }
    if(f_cnt == n) s[0] = 'E';
    vector<int> pos;
    for(int i=0; i<n; i++) {
        if(s[i] != 'F') pos.push_back(i);
    }
    int temp = pos[0] + n - 1 - pos.back();
    int mini = 0, maxi = 0;
    for(int i=0; i<pos.size()-1; i++) {
        mini += ((pos[i+1]-pos[i])&1)^(s[pos[i]]!=s[pos[i+1]]);
        maxi += (pos[i+1]-pos[i]-(s[pos[i]] != s[pos[i+1]]));
    }
    set<int> sol;
    for(int i=mini; i<=temp+maxi; i+=(1+(temp==0))) {
        sol.insert(i);
    }

    cout << sol.size() << endl;
    for(auto &x: sol) cout << x << endl;
}

/*
// B=Bessie; E=Elsie; F = S = farmer John
    increase:
    B...B; E...E -> len(substring)-1
    BE; EB -> 0
    EFE; BFB -> 0 or 2
    EFB; BFE -> 1
    EFFB; BFFE -> 0 or 2
    EFFE; BFFB -> 1 or 3
    // make n<4 manually
    if(n<3) {
        if(n==1) cout << 0 << endl;
        else if(n==2) {
            if((s[0] == 'B' and s[1] == 'E') or (s[0] == 'E' and s[1] == 'B')) cout << 1 << endl << endl << 0;
            else if(s[0] == 'F' or s[1] == 'F') cout << 2 << endl << 0 << endl << 1 << endl;
            else cout << 1 << endl << 1 << endl;
        }
        else if(n==3) {
            
            all possible (3³):
            // no F
            BBB; EEE -> 1{2}
            BBE; EBB; EEB; BEE -> 1{1}
            BEB; EBE -> 0{}
            // F
            FEB; FBE; EBF; BEF -> 2{0, 1}
            EFB; BFE -> 1{1}
            FFE; FFB; EFF; BFF -> 3{0, 1, 2}
            EFE; BFB -> 2{0, 2}
            FFF -> 3{0, 1, 2}
            EEF; BBF; FEE; FBB -> 2{1, 2}
            if((s[0] == 'B' or s[0] == 'E') and (s[0] == s[1] == s[2])) cout << 1 << endl << 2 << endl;
            else if((s[0] == 'B' and s[1] == 'B' and s[2] == 'E') or
                    (s[0] == 'E' and s[1] == 'E' and s[2] == 'B') or
                    (s[0] == 'B' and s[1] == 'E' and s[2] == 'E') or 
                    (s[0] == 'E' and s[1] == 'B' and s[2] == 'B')) {cout << 1 << endl << 1 << endl;}
            else if((s[0] == 'B' and s[1] == 'E' and s[2] == 'B') or
                    (s[0] == 'E' and s[1] == 'B' and s[2] == 'E')) {cout << 1 << endl << endl << 0;}
            else if((s[0] == 'B' and s[1] == 'F' and s[2] == 'E') or
                    (s[0] == 'E' and s[1] == 'F' and s[2] == 'B')) {cout << 1 << endl << 1 << endl;}
            else if((s[0] == 'F' and s[1] == 'E' and s[2] == 'B') or 
                    (s[0] == 'F' and s[1] == 'B' and s[2] == 'E') or
                    (s[0] == 'B' and s[1] == 'E' and s[2] == 'F') or
                    (s[0] == 'E' and s[1] == 'B' and s[2] == 'F')) {cout << 2 << endl << 0 << endl << 1 << endl;}
            else if(s[0] == s[1] == s[2]) cout << 3 << endl << 0 << endl << 1 << endl << 2 << endl;
            else if((s[0] == 'E' and s[1] == 'F' and s[2] == 'E') or 
                    (s[0] == 'B' and s[1] == 'F' and s[2] == 'B')) {cout << 2 << endl << 0 << endl << 2 << endl;}
            else if((s[0] == 'E' and s[1] == 'E' and s[2] == 'F') or
                    (s[0] == 'B' and s[1] == 'B' and s[2] == 'F') or
                    (s[0] == 'F' and s[1] == 'E' and s[2] == 'E') or 
                    (s[0] == 'F' and s[1] == 'B' and s[2] == 'B')) {cout << 2 << endl << 0 << endl << 1 << endl;}
            else cout << 3 << endl << 0 << endl << 1 << endl << 2 << endl;
        }
        return 0;
    }

    
    int no_f = 0;  // level while ignoring Fs
    for(int i=0; i<n-1; i++) {
        if(s[i] == s[i+1] and s[i] != 'F') no_f++;
    }
    cout << no_f << endl;
    set<int> sol{no_f}; // how to handle updates now
    for(int i=0; i<-2; i++) {
        string cur = {s[i], s[i+1], s[i+2]};
        
    }

    cout << sol.size() << endl;
    for(auto &x: sol) cout << x << endl;
*/