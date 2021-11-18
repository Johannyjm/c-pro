#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vector<string> strs(n);
    rep(i, n){
        string str = "";
        rep(j, n){
            str += s[(i+j)%n];
        }
        strs[i] = str;
    }

    sort(strs.begin(), strs.end());

    cout << strs.front() << endl;
    cout << strs.back() << endl;

    return 0;
}