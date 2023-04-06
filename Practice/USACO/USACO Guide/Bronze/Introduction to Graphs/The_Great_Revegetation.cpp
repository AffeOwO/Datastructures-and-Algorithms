#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

	int n, m; fin >> n >> m;
	vector<pair<int, int>> graph(m);
	vector<int> sol(n, 1);
	for(int i=0; i<m; i++) {
		int t, t2; fin >> t >> t2;
		t--; t2--;
		if(t<t2) {
			graph[i].first = t;
			graph[i].second = t2;
		}
		else {
			graph[i].first = t2;
			graph[i].second = t;
		}
	}
	sort(all(graph));
	for(auto x: graph) {
		if(sol[x.first] == sol[x.second]) {
			sol[x.second]++;
			int pnt2 = 0;
			for(auto y: graph) {
				if(y==x) break;
				if(sol[y.first] == sol[y.second]) {
					sol[x.second]++;
				}
			}
		}
	}
	for(auto x: sol) {
		fout << x;
	}
	fout << endl;
}