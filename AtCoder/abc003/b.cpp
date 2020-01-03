#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    rep(i, s.length()){
        if(s[i]==t[i]) continue;
        if(s[i]=='@' && (t[i]=='a' || t[i]=='t' || t[i]=='c' || t[i]=='o' || t[i]=='d' || t[i]=='e' || t[i]=='r')) continue;
        if(t[i]=='@' && (s[i]=='a' || s[i]=='t' || s[i]=='c' || s[i]=='o' || s[i]=='d' || s[i]=='e' || s[i]=='r')) continue;

        puts("You will lose");
        return 0;
    }
    puts("You can win");
    return 0;
}