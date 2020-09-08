#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int maxx = -101;
    int miny = 101;

    rep(i, n){
        int x_;
        cin >> x_;
        maxx = max(maxx, x_);
    }
    rep(i, m){
        int y_;
        cin >> y_;
        miny = min(miny, y_);
    }

    if(max(maxx, x) < min(miny, y)) puts("No War");
    else puts("War");
}