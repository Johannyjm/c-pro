#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    int res = 1001001001;
    rep(i, n - m + 1){
        int cnt = 0;
        rep(j, m){
            if(s[i+j] != t[j]) ++cnt;
        }
        res = min(res, cnt);
    }

    cout << res << endl;

    return 0;
}