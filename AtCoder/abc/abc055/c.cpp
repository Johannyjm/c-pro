#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    ll res;
    if(n >= m/2) {
        cout << m/2 << endl;
        return 0;
    }
    res = n;
    m -= 2*n;

    res += m/4;

    cout << res << endl;

    return 0;
}