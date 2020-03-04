#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

vector<ll> dp;
 
void init(ll n) {
    dp.resize(n);
    rep(i, n) dp[i] = i;
}

ll root(ll x) {
    if (dp[x] == x) return x;
    else return dp[x] = root(dp[x]);
}

void unite(ll x, ll y) {
    auto rx = root(x);
    auto ry = root(y);
    dp[ry] = dp[rx];
    root(y);
}

bool same(ll x, ll y) {
    return root(x) == root(y);
}
