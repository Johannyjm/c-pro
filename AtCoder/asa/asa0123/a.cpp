#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    rep(i, n) cin >> s[i] >> t[i];

    string x;
    cin >> x;

    int res = 0;
    bool flg = false;
    rep(i, n){
        if(flg) res += t[i];
        if(s[i] == x) flg = true;
    }

    cout << res << endl;

    return 0;
}