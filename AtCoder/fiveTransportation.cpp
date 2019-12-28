#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;

    ll bottolneck = min(a, min(b, min(c, min(d, e))));
    cout << 5 + n/bottolneck - (bottolneck == 1) << endl;

}