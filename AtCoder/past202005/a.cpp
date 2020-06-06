#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    if(s == t){
        puts("same");
        return 0;
    }

    bool flg = true;
    rep(i, 3){
        if(s[i] != t[i]){
            int a, b;
            if('a' <= s[i] && s[i] <= 'z') a = s[i] - 'a';
            else a = s[i] - 'A';
            
            if('a' <= t[i] && t[i] <= 'z') b = t[i] - 'a';
            else b = t[i] - 'A';

            if(a != b) flg = false;

        }
    }

    if(flg) puts("case-insensitive");
    else puts("different");

    return 0;
}