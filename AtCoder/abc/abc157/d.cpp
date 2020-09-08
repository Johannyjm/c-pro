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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, k, a, b, c, d;
    cin >> n >> m >> k;

    init(n);
    vector<vector<ll>> direct(n, vector<ll>());
    vector<vector<ll>> block(n, vector<ll>());

    rep(i, m){
        cin >> a >> b;
        --a;
        --b;
        unite(a, b);
        direct[a].push_back(b);
        direct[b].push_back(a);
    }

    rep(i, k){
        cin >> c >> d;
        --c;
        --d;
        block[c].push_back(d);
        block[d].push_back(c);
    }

    map<ll, ll> friend_size;
    vector<ll> roots(n);
    rep(i, n){
        ll r = root(dp[i]);
        ++friend_size[r];
        roots[i] = r;
    }

    rep(i, n){
        ll res = friend_size[roots[i]] - direct[i].size() - 1;
        ll cnt = 0;
        rep(j, block[i].size()){
            if(same(i, block[i][j])) ++cnt;
        }

        cout << res - cnt << " ";
    }
    cout << endl;

    return 0;
}