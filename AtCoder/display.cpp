#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    if(h1==h2 || h1==w2 || w1==h2 || w1==w2) puts("YES");
    else puts("NO");
}