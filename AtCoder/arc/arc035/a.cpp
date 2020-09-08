#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    bool flg = true;

    rep(i, n/2){
        if(s[i] == s[n-i-1] || s[i] == '*' || s[n-i-1] == '*') continue;
        else flg = false;
    }

    if(flg) puts("YES");
    else puts("NO");

    return 0;
}