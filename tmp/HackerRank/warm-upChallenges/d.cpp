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
    int m = s.size();
    ll n;
    cin >> n;

    ll cnt = 0;
    rep(i, m){
        if(s[i] == 'a') ++cnt;
    }

    ll res = n/m * cnt;
    n %= m;
    rep(i, n){
        if(s[i] == 'a') ++res;
    }

    cout << res << endl;

    return 0;
}