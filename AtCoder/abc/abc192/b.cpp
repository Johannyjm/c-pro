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

    bool flg = true;
    rep(i, n){
        if(i%2 == 0 && 'A'<=s[i] && s[i]<='Z') flg = false;
        if(i%2 == 1 && 'a'<=s[i] && s[i]<='z') flg = false;
    }

    if(flg) puts("Yes");
    else puts("No");

    return 0;
}