#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int odd = 0;

    rep(i, n){
        int a;
        cin >> a;
        if(a%2) ++odd;
    }

    if(odd%2) puts("NO");
    else puts("YES");

    return 0;
}