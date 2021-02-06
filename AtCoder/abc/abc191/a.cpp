#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int v, t, s, d;
    cin >> v >> t >> s >> d;

    if(v*t <= d && d <= v*s) puts("No");
    else puts("Yes");

    return 0;
}