#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    ll sm = 0;
    rep(i, n){
        sm += s[i] - '0';
    }

    if(sm%9 == 0) puts("Yes");
    else puts("No");

    return 0;
}