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
    string s, t;
    cin >> s >> t;

    int res = 0;
    int cnts = 0;
    int cntt = 0;
    rep(i, n){
        if(s[i] == '0') ++cnts;
        if(t[i] == '0') ++cntt;
        if(t[i] == '0' && (s[i] != '0' || cnts != cntt)) ++res;
    }

    if(cnts != cntt) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}