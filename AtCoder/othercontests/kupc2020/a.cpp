#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;

    int res = 0;
    rep1(i, n){
        int x_, y_;
        cin >> x_ >> y_;

        res += abs(x_ - x) + abs(y_ - y);

        x = x_;
        y = y_;
    }

    cout << res << endl;

    return 0;
}