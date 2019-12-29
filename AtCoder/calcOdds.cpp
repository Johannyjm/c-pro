#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a*d >= b*c){
        if(a*d == b*c) puts("DRAW");
        else puts("AOKI");
    }
    else puts("TAKAHASHI");
}