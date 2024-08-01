#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	string s;
	cin >> s;
	int n = s.length(), cnt = 0;
	bool all = (s[0] == 'B' || s[n - 1] == 'B');
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1] && s[i] == 'B') {all = true;}
	}
	vector<int> lens;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {curr++;}
		else {
			if (curr != 0) {lens.push_back(curr);}
			curr = 0;
		}
	}
	if (curr != 0) {lens.push_back(curr);}
	sort(lens.begin(), lens.end());
	
	if (lens.empty()) {cout << 0 << '\n'; return;}
	
	int tot = 0;
	if (all) {tot += lens[0];}
	for (int i = 1; i < lens.size(); i++) {
		tot += lens[i];
	}
	cout << tot << '\n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}