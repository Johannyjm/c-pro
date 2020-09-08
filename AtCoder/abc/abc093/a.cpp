#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int a, b, c;
    a = 0;
    b = 0;
    c = 0;

    rep(i, 3){
        if(s[i]=='a')++a;
        if(s[i]=='b')++b;
        if(s[i]=='c')++c;
    }

    if(a==b && b==c) puts("Yes");
    else puts("No");
}