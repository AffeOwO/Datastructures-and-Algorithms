#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"

int main() {
    //ifstream fin("");
    //ofstream fout("");

    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int N;
	cin >> N;
	string S;
	cin >> S;
	set<pair<int,int>>used({{0,0}});
	int x=0,y=0;
	for(auto c:S){
		if(c=='U')y++;
		if(c=='D')y--;
		if(c=='R')x++;
		if(c=='L')x--;
		if(used.find({x,y})!=used.end()){
			cout << "Yes" << endl;
			return 0;
		}
		used.insert({x,y});
	}
	cout << "No" << endl;
}