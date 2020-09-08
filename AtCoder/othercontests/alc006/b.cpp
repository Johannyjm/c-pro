#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int nmax = max(a, max(b, c));

    cout << nmax*pow(2, k) + a + b + c - nmax<< endl;

    return 0;
}