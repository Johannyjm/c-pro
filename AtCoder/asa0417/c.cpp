#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int res = 0;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            if((n - (i*r + j*g)) < 0) continue;

            if((n - (i*r + j*g))%b == 0) ++res;
        }
    }

    cout << res << endl;

    return 0;
}