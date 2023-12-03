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

    // part 1
    ll sol = 0;
    vector<string> mat;
    string s;
    while(getline(fin, s)) mat.push_back(s);
    int n = mat.size(), m = mat[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if((j!=0 and isdigit(mat[i][j-1])) or !isdigit(mat[i][j])) continue;
            int k = j;
            while(k<m and isdigit(mat[i][k])) k++;
            ll cur = stoi(mat[i].substr(j, k-j));
            // j is first digit of num; k is char after last digit of num
            bool idk = false;
            if(j!=0 and (!(mat[i][j-1]=='.') or (i>0 and !(mat[i-1][j-1]=='.' or isdigit(mat[i-1][j-1]))) or (i!=n-1 and !(mat[i+1][j-1]=='.' or isdigit(mat[i+1][j-1]))))) idk = true;
            else if(k!=m and (!(mat[i][k]=='.') or (i>0 and !(mat[i-1][k]=='.' or isdigit(mat[i-1][k]))) or (i!=n-1 and !(mat[i+1][k]=='.' or isdigit(mat[i+1][k]))))) idk = true; 
            for(int l=j; l<k; l++) {
                if(i!=0 and !(mat[i-1][l]=='.' or isdigit(mat[i-1][l]))) idk = true;
                else if(i!=n-1 and !(mat[i+1][l]=='.' or isdigit(mat[i+1][l]))) idk = true;
            }
            if(idk) sol += cur;
        }
    }
    fout << sol << endl;

    // part 2
    ll sol2 = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] != '*') continue;
            // if * is adjacent to exactly 2 numbers, add the product of thsoe 2 numbers to sol2
            vector<int> nums;
            if(j!=0 and isdigit(mat[i][j-1])) {
                int k = j-1;
                while(k>=0 and isdigit(mat[i][k])) k--;
                nums.push_back(stoi(mat[i].substr(k+1, j-k)));
            }
            if(j!=m-1 and isdigit(mat[i][j+1])) {
                int k = j+1;
                while(k<m and isdigit(mat[i][k])) k++;
                nums.push_back(stoi(mat[i].substr(j+1, k-j)));
            }
            if(i!=0 and j!=0 and isdigit(mat[i-1][j-1])) {
                int l = j-1, r = j;
                while(l>=0 and isdigit(mat[i-1][l])) l--;
                l++;
                while(r<m and isdigit(mat[i-1][r])) r++;
                nums.push_back(stoi(mat[i-1].substr(l, r-l)));
            }
            else if(i!=0 and isdigit(mat[i-1][j])) {
                int k = j;
                while(k<m and isdigit(mat[i-1][k])) k++;
                nums.push_back(stoi(mat[i-1].substr(j, k-j)));
            }
            if(i!=0 and j!=m-1 and isdigit(mat[i-1][j+1]) and !isdigit(mat[i-1][j])) {
                int k = j+1;
                while(k<m and isdigit(mat[i-1][k])) k++;
                nums.push_back(stoi(mat[i-1].substr(j+1, k-j)));
            }

            if(i!=n-1 and j!=0 and isdigit(mat[i+1][j-1])) {
                int l = j-1, r = j;
                while(l>=0 and isdigit(mat[i+1][l])) l--;
                l++;
                while(r<m and isdigit(mat[i+1][r])) r++;
                nums.push_back(stoi(mat[i+1].substr(l, r-l)));
            }
            else if(i!=n-1 and isdigit(mat[i+1][j])) {
                int k = j;
                while(k<m and isdigit(mat[i+1][k])) k++;
                nums.push_back(stoi(mat[i+1].substr(j, k-j)));
            }
            if(i!=n-1 and j!=m-1 and isdigit(mat[i+1][j+1]) and !isdigit(mat[i+1][j])) {
                int k = j+1;
                while(k<m and isdigit(mat[i+1][k])) k++;
                nums.push_back(stoi(mat[i+1].substr(j+1, k-j)));
            }
            /*
            cout << i << " " << j << ": ";
            for(auto &x: nums) cout << x << " ";
            cout << endl;
            */
            if(nums.size() == 2) sol2 += (nums[0]*nums[1]);
        }
    }

    fout << sol2 << endl;
}