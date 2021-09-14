#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int const MOD = 10007;
    int res[n];

    res[0] = 0;
    res[1] = 0;
    res[2] = 1;

    for (int i = 3; i < n; ++i) {
        res[i] = ((res[i-3] + res[i-2])%MOD + res[i-1])%MOD;
    }
    cout << res[n-1] << endl;
}