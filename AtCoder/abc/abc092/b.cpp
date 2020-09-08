#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, d, x;
    cin >> n >> d >> x;

    int res = x;
    rep(i, n) {
        int a;
        cin >> a;

        res += (d%a!=0) + d/a;
    }
    cout << res << endl;
}