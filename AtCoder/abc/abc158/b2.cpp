#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;

    ll res = n / (a+b) * a;
    res += min(n % (a+b), a);

    cout << res << endl;

    return 0;
}