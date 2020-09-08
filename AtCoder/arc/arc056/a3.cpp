#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, k, l;
    cin >> a >> b >> k >> l;

    ll res = b*(k/l);

    int remain = k%l;
    res += min(a*remain, b);

    cout << res << endl;

    return 0;
}