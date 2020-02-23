#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;

    ll bottle_neck = min({a, b, c, d, e});
    cout << 5 + n/bottle_neck - (bottle_neck == 1) << endl;

    return 0;
}