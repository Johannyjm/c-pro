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
    
    int n = s.size();
    int cnt = 0;
    rep(i, n){
        if(s[i] == 'o') ++cnt;
    }

    if(15-n + cnt >= 8) puts("YES");
    else puts("NO");

    return 0;
}