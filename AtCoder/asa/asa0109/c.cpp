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
    ll res = 0;
    ll cnt = 0;
    rep(i, n){
        if(s[i] == 'W'){
            res += i - cnt;
            ++cnt;
        }
    }

    cout << res << endl;

    return 0;
}