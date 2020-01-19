#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> num(s.size()+1);
    num[0] = 0;

    rep(i, s.size()){
        if(s[i] == '<') num[i+1] = num[i] + 1;
        else num[i+1] = num[i] - 1;        
    }
    rep(i, s.size()+1) cout << num[i] << " ";
    cout << endl;

    return 0;
}