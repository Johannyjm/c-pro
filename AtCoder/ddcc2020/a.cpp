#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    int res = 0;
    if(x == 1 || y == 1) res += 300000 * (1 + (x == y));
    if(x == 2 || y == 2) res += 200000 * (1 + (x == y));
    if(x == 3 || y == 3) res += 100000 * (1 + (x == y));
    if(x+y == 2) res += 400000;

    cout << res << endl;

    return 0;
}