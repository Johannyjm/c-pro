#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<ll> dp;
int grp_cnt;
vector<ll> inconv;
map<ll, ll> mp;
 
void init(ll n) {
    dp.resize(n);
    for(ll i = 0; i < n; ++i) {
        dp[i] = i;
        ++mp[i];
    }
}

ll root(ll x) {
    if (dp[x] == x) return x;
    else return dp[x] = root(dp[x]);
}

void unite(ll x, ll y, int i) {
    auto rx = root(x);
    auto ry = root(y);
    if(rx != ry) {
        --grp_cnt;
        mp[rx] += mp[ry];
        inconv[i] = inconv[i+1] - mp[rx]*(mp[rx]-1)/2;
        mp[ry] = 0;
    }
    else inconv[i+1] = inconv[i];
    dp[ry] = dp[rx];
    root(y);
}

bool same(ll x, ll y) {
    return root(x) == root(y);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    init(n);
    grp_cnt = n;
    inconv.resize(m+1);
    inconv[m] = n*(n-1)/2;

    rep(i, n) cout << dp[i];
    cout << " " << grp_cnt << endl;
    rep(i, n) cout << mp[i];
    cout << endl;
    for(int i = m-1; i >= 0; --i){
        unite(a[i], b[i], i);
        rep(i, n) cout << dp[i];
        cout << " " << grp_cnt << endl;
        rep(i, n) cout << mp[i];
        cout << endl;
    }

    rep1(i, m+1) cout << inconv[i] << " ";
    cout << endl;

    





    return 0;
}