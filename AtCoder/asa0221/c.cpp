#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    bool flg = false;
    rep(i, n+1){
        rep(j, m+1){
            int black = i*m + j*n - i*j*2;
            if(black == k) flg = true;
        }
    }

    if(flg) puts("Yes");
    else puts("No");

    return 0;
}