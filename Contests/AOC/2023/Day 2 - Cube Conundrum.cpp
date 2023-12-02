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
    
    // part 1 and 2
    int sol = 0, sol2 = 0;
    for(int i=1; i<=100; i++) {
        string s;
        getline(fin, s);
        bool idk = true;
        tuple<int, int, int> triple;
        for(int j=0; j<s.size(); j++) {
            if((j!=0 and isdigit(s[j-1]) and isdigit(s[j])) or !isdigit(s[j])) continue;
            vector<int> vec;
            int k = j;
            while(isdigit(s[k])) {
                vec.push_back(s[k]-'0');
                k++;
            }
            int num = 0, n = vec.size();
            for(int l=0; l<n; l++) num += (vec[l]*pow(10, n-l-1));
            if(s[k+1] == 'r') {
                if(num > 12) idk = false;
                get<0>(triple) = max(get<0>(triple), num);
            }
            else if(s[k+1] == 'g') {
                if(num > 13) idk = false;
                get<1>(triple) = max(get<1>(triple), num);
            }
            else if(s[k+1] == 'b') {
                if(num > 14) idk = false;
                get<2>(triple) = max(get<2>(triple), num);
            }
        }
        if(idk) sol += i;
        sol2 += (get<0>(triple)*get<1>(triple)*get<2>(triple));
    }
    fout << sol << endl << sol2 << endl;
}